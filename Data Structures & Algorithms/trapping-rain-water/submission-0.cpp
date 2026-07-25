class Solution {
public:
    int trap(vector<int>& height) {
        int first = 0;
        int last = height.size()-1;

        int leftmax = 0;
        int rightmax = 0;

        int ans = 0;

        while(first<=last)
        {
            if(height[first]<=height[last])
            {
                if(height[first]>=leftmax)
                {
                    leftmax = height[first];
                }
                else
                {
                    ans += leftmax - height[first];
                }

                first++;
            }
            else
            {
               if(height[last]>=rightmax)
                {
                    rightmax = height[last];
                }
                else
                {
                    ans += rightmax - height[last];
                } 

                last--;
            }
        }


        return ans;
        

    }
};
