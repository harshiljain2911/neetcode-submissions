class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans(nums.size(),0);

        for(int i = 0;i<nums.size();i++)
        {
            vector<int> temp = nums;
            temp[i] = 1;
            ans[i] = accumulate(temp.begin(), temp.end(), 1, multiplies<int>());

        }

        return ans;
        
    }
};
