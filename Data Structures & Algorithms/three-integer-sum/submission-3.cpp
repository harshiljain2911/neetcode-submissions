class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans = {};

        int target = 0;

        for (int fix = 0; fix < nums.size() - 1; fix++) {
            if (fix > 0 && nums[fix] == nums[fix - 1]) continue;

            int need = target - nums[fix];
            int p1 = fix + 1;
            int p2 = nums.size() - 1;

            while (p1 < p2) {
                int sum = nums[p1] + nums[p2];
                if (sum < need) {
                    p1++;
                } else if (sum > need) {
                    p2--;
                } else {
                    ans.push_back({nums[fix], nums[p1], nums[p2]});
                    p1++;
                    p2--;
                    while (p1 < p2 && nums[p1] == nums[p1 - 1]) p1++;
                    while (p1 < p2 && nums[p2] == nums[p2 + 1]) p2--;
                }
            }
        }

        return ans;
    }
};
