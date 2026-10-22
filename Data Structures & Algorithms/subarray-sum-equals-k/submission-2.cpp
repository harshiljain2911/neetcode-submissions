class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> freq;

        long long prefix = 0;
        int count = 0;

        freq[0] = 1;

        for (int num : nums) {
            prefix += num;

            long long needed = prefix - k;

            auto it = freq.find(needed);
            if (it != freq.end()) {
                count += it->second;
            }

            freq[prefix]++;
        }

        return count;
    }
};