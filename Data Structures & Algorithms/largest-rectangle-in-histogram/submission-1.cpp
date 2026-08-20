class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int nsei = heights.size();
        int psei = -1;
        int ele;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                nsei = i;
                ele = st.top();
                st.pop();
                psei = (st.empty()) ? -1 : st.top();

                ans = max(ans, heights[ele] * (nsei - psei - 1));
            }

            st.push(i);
        }

        while (!st.empty()) {
            ele = st.top();
            st.pop();

            psei = (st.empty()) ? -1 : st.top();

            nsei = heights.size();

            ans = max(ans, heights[ele] * (nsei - psei - 1));
        }

        return ans;
    }
};
