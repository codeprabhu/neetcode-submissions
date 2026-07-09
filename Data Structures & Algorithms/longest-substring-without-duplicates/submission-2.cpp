class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        set<char> has;
        int n = s.size();
        int r = 0, ans = 0;

        for(int l = 0; l < n; l++)
        {
            while(has.find(s[l]) != has.end())
            {
                has.erase(s[r]);
                r++;
            }

            has.insert(s[l]);
            int len = has.size();
            ans = max(len, ans);
        }

        return ans;
    }
};
