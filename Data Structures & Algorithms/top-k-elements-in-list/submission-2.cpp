class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(),
             [](const auto& a, const auto& b) { return a.second < b.second; });

        int t = vec.size() - 1;
        while (k > 0) {
            auto& [key,value] = vec[t--];
            ans.push_back(key);
            k--;
        }

        return ans;
    }
};