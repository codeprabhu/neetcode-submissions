class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n = s.size();
        int l = 0, ans = 0, minmax = 0;
        for(int r = 0 ; r < n; r++)
        {
            freq[s[r]-'A']++;
            minmax = max(minmax,freq[s[r] - 'A']);

            while(r-l+1 - minmax > k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(r-l+1 ,ans)
;        }

        return ans;
    }
};
