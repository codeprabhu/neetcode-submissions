class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0, cur = 0;
        for(int x: nums)
        {
            cur += x;
            if(mp.count(cur-k))
                ans += mp[cur-k];

            mp[cur]++;
        }

        return ans;
    }
};