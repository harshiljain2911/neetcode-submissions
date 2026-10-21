class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> leftsum(n + 1, 0);
        vector<int> rightsum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            leftsum[i + 1] = leftsum[i] + nums[i];
            rightsum[i] = sum - leftsum[i] - nums[i];
            if (rightsum[i] == leftsum[i])
                return i;
        }

        return -1;
    }
};