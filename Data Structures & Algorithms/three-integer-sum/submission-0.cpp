class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<pair<int,int>> a;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n-2; i++)
        {
            int cur = a[i].first;
            int l = i+1, r= n-1;
            if(i > 0 && a[i].first == a[i-1].first)
                continue;

            while(l < r)
            {
                int sum = a[l].first + a[r].first;
                if(sum + cur> 0)
                    r--;
                else if(sum + cur < 0)
                    l++;
                else
                {
                    ans.push_back({cur, a[l].first, a[r].first});
                    l++;
                    r--;

                    while(l < r && a[l].first == a[l-1].first)
                        l++;

                    while(l < r && a[r].first == a[r+1].first)
                        r--;
                }    
            }
        }
        return ans;
    }
};
