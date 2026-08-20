class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {

                int idx = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();

                int width = i - left - 1;

                ans = max(ans, heights[idx] * width);
            }

            st.push(i);
        }

        // Remaining bars can extend till the end
        while (!st.empty()) {

            int idx = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();

            int width = heights.size() - left - 1;

            ans = max(ans, heights[idx] * width);
        }

        return ans;
    }
};