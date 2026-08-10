class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(int i, vector<int>& nums)
    {
        if(i == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(i+1, nums);
    
        cur.pop_back();
        dfs(i+1, nums);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
