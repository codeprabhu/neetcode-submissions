class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<bool> used;
    void dfs(vector<int>& nums)
    {
        if(cur.size() == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!used[i])
            {
                cur.push_back(nums[i]);
                used[i] = true;
                dfs(nums);
                cur.pop_back();
                used[i] = false;
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        dfs(nums);
        return ans;
    }
};
