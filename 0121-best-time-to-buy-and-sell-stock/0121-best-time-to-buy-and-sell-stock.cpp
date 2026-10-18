class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_price=prices[0]; 
        int max_profit=0;

        for(int i=0;i<prices.size();i++){
            if(prices[i]<best_price){
                best_price=prices[i];
            }

            max_profit=max(max_profit,prices[i]-best_price);
        }

        return max_profit;

    }
};