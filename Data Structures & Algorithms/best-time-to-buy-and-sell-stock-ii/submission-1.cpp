class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cursel = 0, curbuy = 0, nextsel = 0, nextbuy = 0;
        for(int i = n-1; i >= 0; i--)
        {
            curbuy = max(nextbuy, -prices[i]+nextsel);
            cursel = max(nextsel,  prices[i]+nextbuy);
            nextbuy = curbuy;
            nextsel = cursel;
        }

        return curbuy;
    }
};