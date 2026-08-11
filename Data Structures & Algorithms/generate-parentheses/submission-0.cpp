class Solution {
public:
    vector<string> ans;
    string cur;
    void dfs(int n, int left, int right)
    {
        if(right == n)
        {
            ans.push_back(cur);
            return;
        }

        if(left < n)
        {
            cur.push_back('(');
            dfs(n, left+1, right);
            cur.pop_back();
        }
        if(right < left)
        {
            cur.push_back(')');
            dfs(n, left, right+1);
            cur.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ans;
    }
};
