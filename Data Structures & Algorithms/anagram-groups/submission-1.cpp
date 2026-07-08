class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < n; i++)
        {
            vector<int> keys(26,0);
            string str = "";
            for(char c: strs[i])
                keys[c-'a']++;
            for(int i = 0; i < 26; i++)
                str += to_string(keys[i]) + " " ;

            mp[str].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
