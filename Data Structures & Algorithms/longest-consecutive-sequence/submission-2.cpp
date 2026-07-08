class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> ninger;
        int n = nums.size(); 
        for(int i = 0; i < n; i++)
            ninger.insert(nums[i]);

        if(nums.size() == 0)
            return 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            int cur = nums[i];
            int length = 0;
            while(ninger.find(cur) != ninger.end())
            {
                length++; 
                cur++;
            }
            ans = max(length, ans);
        }
        return ans;
    }
};
