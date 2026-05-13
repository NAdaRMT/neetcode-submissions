class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 1) return 0;
        
        int buy = 0;
        int sell = 1;
        int maxProfit = 0;

        while (sell < prices.size()) {
            if (prices[buy] < prices[sell]) {
                int profit = prices[sell] - prices[buy];
                maxProfit = max(maxProfit, profit);
            } else {
                buy = sell;                
            }
            sell++;
        }
        return maxProfit;
    }
};
