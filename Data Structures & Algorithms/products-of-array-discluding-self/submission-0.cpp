class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        long long prod = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            prod *= nums[i];
            if(nums[i] == 0)
                zeros++;
        }

        vector<int> ans(n,0);
        if(zeros >= 2)
            return ans;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                long long produce = 1;
                for(int j = 0; j < n; j++)
                    if(j != i)
                        produce *= nums[j];

                ans[i] = produce;
                continue;
            }

            ans[i] = prod/nums[i];
        }
        return ans;
    }
};
