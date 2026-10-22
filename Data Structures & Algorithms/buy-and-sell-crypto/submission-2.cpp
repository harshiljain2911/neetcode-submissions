class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofit = 0;

        for(int i=1;i<prices.size();i++)
        {
            minprice = min(minprice,prices[i]);
            if(prices[i]>minprice)
            {
                maxprofit = max(maxprofit,prices[i]-minprice); 
            }
        }

        return maxprofit;
    }
};
