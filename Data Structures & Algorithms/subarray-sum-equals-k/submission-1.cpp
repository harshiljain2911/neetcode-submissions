class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;

        vector<int> presum(nums.size()+1,0);
        
        for(int i=0;i<nums.size();i++)
        {
            presum[i+1] = presum[i] + nums[i];
        }

        for(int fix = 0;fix<presum.size();fix++)
        {
            for(int j = fix+1;j<presum.size();j++)
            {   
                if((presum[j]-presum[fix])==k) count++;
            }
        }

        return count;
    }
};