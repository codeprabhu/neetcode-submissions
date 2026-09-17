class Solution {
public:
    string minWindow(string s, string t) {

        if(t.empty() || s.empty())
            return "";

        unordered_map<char,int> freq;
        for(char c : t)
            freq[c]++;

        unordered_map<char,int> window;

        int have = 0;
        int need = freq.size();

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;

            if(freq.count(c) &&
               window[c] == freq[c])
            {
                have++;
            }

            while(have == need)
            {
                if(r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if(freq.count(leftChar) &&
                   window[leftChar] < freq[leftChar])
                {
                    have--;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};