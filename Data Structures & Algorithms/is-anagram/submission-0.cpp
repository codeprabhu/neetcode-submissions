class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq, nigger;
        if(s.size() != t.size())
            return false;
        for(int i = 0; i < t.size(); i++)
        {
            freq[s[i]]++;
            nigger[t[i]]++;
        }

        for(int i = 0; i < t.size(); i++)
        {
            if(freq[t[i]] != nigger[t[i]])
                return false;
        }
        return true;
    }
};
