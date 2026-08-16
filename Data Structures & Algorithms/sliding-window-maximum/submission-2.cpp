class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> dq;

        int l = 0;

        for (int r = 0; r < nums.size(); r++) {

            // If window becomes larger than k, move left
            if (r - l + 1 > k) {
                l++;
            }

            // Remove indices that are outside the current window
            while (!dq.empty() && dq.front() < l) {
                dq.pop_front();
            }

            // Remove smaller/equal elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(r);

            // Window is now of size k
            if (r - l + 1 == k) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};