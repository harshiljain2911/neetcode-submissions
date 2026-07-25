class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int first = 0;
        int last = heights.size() - 1;

        int ans = INT_MIN;

        while (first <= last) {
            ans = max(ans, (last - first) * min(heights[first], heights[last]));
            if (heights[first] < heights[last])
                first++;
            else
                last--;
        }

        return ans;
    }
};
