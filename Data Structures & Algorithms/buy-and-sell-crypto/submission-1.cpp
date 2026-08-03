class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricemin = prices[0];
        int ans = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            pricemin = min(prices[i], pricemin);
            ans = max(ans, prices[i]-pricemin);
        }

        return ans;
    }
};
