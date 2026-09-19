class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(j > i+1 && nums[j]==nums[j-1])
                    continue;
                
                long long sum = nums[i]+nums[j];
                int l = j+1, r = nums.size()-1;
                if(l >= r)
                    break;
                
                while(l < r)
                {
                    long long summer = sum + nums[l]+nums[r];
                    if(summer > target)
                        r--;
                    else if(summer < target)
                        l++;
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};