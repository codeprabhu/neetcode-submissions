class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<int>& a, int target, int i)
    {
        if(target == 0)
        {
            ans.push_back(cur);
            return;
        }

        if(i == a.size() || target < 0)
            return;

        cur.push_back(a[i]);
        dfs(a, target-a[i], i+1);

        cur.pop_back();
        int j = i;
        while(j < a.size() && a[j] == a[i])
            j++;
        dfs(a, target, j);
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        dfs(a, target, 0);
        return ans;
    }
};
