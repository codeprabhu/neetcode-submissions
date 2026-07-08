class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> freq;
        for(int i = 0; i < n; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            freq[s].push_back(strs[i]);
        }
        
        vector<vector<string>> ans(freq.size());
        int ind =0;
        for(auto it: freq)
        {
            for(auto ninjer: it.second)
                ans[ind].push_back(ninjer);
            ind++;
        }
        return ans;
    }
};
