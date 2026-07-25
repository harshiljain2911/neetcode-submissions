class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;
        
        for(int i = 0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }

        int ans = 0;

        for(int num:nums)
        {
            int length = 1;
            if(st.contains(num-1)) continue;
            else
            {
                while(st.contains(num+1))
                {
                    length++;
                    num++;
                } 
            }
            ans = max(length,ans);
        }

        return ans;

    }
};
