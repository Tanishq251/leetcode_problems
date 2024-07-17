class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int p=0,l=prices[0];
    for(int i=0;i<prices.size();i++){

        int count = prices[i]-l;
        
        p=max(count,p);
        l=min(prices[i],l);
    }
    return p;
    }
};
