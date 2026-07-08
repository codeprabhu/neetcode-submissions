class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, n = nums.size();
        vector<vector<int>> ninjer(n, vector<int>(2));
        for(int i = 0; i < n; i++)
        {
            ninjer[i][0] = nums[i];
            ninjer[i][1] = i;
        }

        sort(ninjer.begin(), ninjer.end());
        int sum = 0;
        while( l < r)
        {
            sum = ninjer[l][0] + ninjer[r][0];
            if(sum > target)
                r--;
            else if(sum < target)
                l++;
            else
            {
                if(ninjer[l][1] > ninjer[r][1])
                    return {ninjer[r][1], ninjer[l][1]};
                else
                    return {ninjer[l][1], ninjer[r][1]};
            }
        }

        return {-1,-1};
    }
};
