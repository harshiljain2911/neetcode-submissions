class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;

        int first = 0;
        int last = heights.size()-1;
        
        while(first<=last)
        {
            ans = max((min(heights[first],heights[last]))*(last-first),ans);
            if(heights[first]<=heights[last]) first++;
            else last--;
        }

        return ans; 
    }
};
