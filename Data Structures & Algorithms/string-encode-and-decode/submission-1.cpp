class Solution {
public:

    string encode(vector<string>& strs) {
        string finalans = "";
        for(int i = 0; i < strs.size(); i++)
        {
            finalans += strs[i];
            finalans += '`';
        }
        return finalans;
    }

    vector<string> decode(string s) {
        vector<string> finalans;
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '`')
            {
                finalans.push_back(str);
                str = "";
                continue;
            }

            str += s[i];
        }
        return finalans;
    }
};
