class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int target, int i, vector<int>& nums)
    {
        if(target == 0)
        {
            ans.push_back(cur);
            return;            
        }

        if(i == nums.size() || target < 0)
            return;

        cur.push_back(nums[i]);
        dfs(target-nums[i], i, nums);

        cur.pop_back();
        dfs(target, i+1, nums);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(target, 0, nums);
        return ans;    
    }
};
