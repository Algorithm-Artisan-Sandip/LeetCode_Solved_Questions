class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0; int buyPrice = prices[0];
        int size = prices.size();
        int i=1; 
        for(int i=0; i<size; i++){
            buyPrice = min(prices[i],buyPrice);
            profit = max(profit,prices[i]-buyPrice);
        }
        return profit;
    }
};