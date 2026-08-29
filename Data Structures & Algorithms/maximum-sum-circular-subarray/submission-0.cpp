class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmax = nums[0], ansmax = nums[0];
        int total = nums[0];
        int ansmin = nums[0], curmin = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            curmax = max(curmax+nums[i], nums[i]);
            ansmax = max(curmax, ansmax);
            total += nums[i];
            curmin = min(curmin+nums[i], nums[i]);
            ansmin = min(ansmin, curmin);
        }

        if(ansmax < 0)
            return ansmax;
        
        int ans = max(ansmax, total-ansmin);
        return ans;
    }
};