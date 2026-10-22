class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0;
    int n = prices.size();

    for (int buy = 0; buy < n; buy++) {
        for (int sell = buy + 1; sell < n; sell++) {
            int profit = prices[sell] - prices[buy];
            best = max(best, profit);
        }
    }

    return best;
    }
};
