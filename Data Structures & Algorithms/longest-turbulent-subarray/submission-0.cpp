class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1)
            return 1;

        vector<int> diff;
        for(int i = 1; i < arr.size(); i++)
        {
            int difference = arr[i]-arr[i-1];
            if(difference == 0)
            {
                diff.push_back(0);
                continue;
            }
            diff.push_back(difference/abs(difference));
        }

        int cur = (diff[0] == 0)? 1 : 2;
        int ans = cur;
        for(int i = 1; i < diff.size(); i++)
        {
            if(diff[i] == 0)
                cur = 1;
            else if(diff[i] * diff[i-1] == -1)
                cur++;
            else
                cur = 2;

            ans = max(ans, cur);
        }
        return ans;
    }
};