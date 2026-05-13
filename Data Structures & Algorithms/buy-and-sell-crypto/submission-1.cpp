class Solution {
public:
    //dynamic programming solution
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuyPrice = prices[0];
        
        // calculate the profit based on the lowest price "SO FAR"
        // we only update the lowest buy price AFTER we found it (sellPrice)
        // so buy always before sell (no edge case violated)
        for (int sellPrice : prices) {
            maxProfit = max(maxProfit, sellPrice - minBuyPrice);
            minBuyPrice = min(minBuyPrice, sellPrice);
        }
        return maxProfit;
    }
};
