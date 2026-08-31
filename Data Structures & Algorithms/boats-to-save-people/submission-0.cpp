class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        sort(a.begin(), a.end());
        int l = 0, r = a.size()-1;
        int ans = 0;
        while(l <= r)
        {
            if(a[l]+a[r] > limit)
            {
                r--;
                ans++;
            }
            else
            {
                l++;
                r--;
                ans++;
            }
        }
        return ans;
    }
};