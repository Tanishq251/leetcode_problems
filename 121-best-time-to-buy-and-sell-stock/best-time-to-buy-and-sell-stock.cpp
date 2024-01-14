class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
    int loss=prices[0];
    for(int i=0;i<prices.size();i++){
        int count=prices[i]-loss;
        profit=max(profit,count);
        loss=min(prices[i],loss);
    }
    return profit;
    }
};