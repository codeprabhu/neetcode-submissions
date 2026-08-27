class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        bool ok = true;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 0; i < n; i++)
        {
            while(i < n && end >= intervals[i][0])
            {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
                i++;
            }
            ans.push_back({start, end});
            if(i >= n)
            {
                ok = false;
                break;
            }
            start = intervals[i][0], end = intervals[i][1];
        }

        if(ok)
            ans.push_back({start, end});

        return ans;
    }
};
