class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(auto point: points)
        {
            int x = point[0];
            int y = point[1];
            pq.push({x*x+y*y, x, y});
        }

        vector<vector<int>> ans;
        while(!pq.empty())
        {
            if(k == ans.size())
                break;

            auto point = pq.top();
            pq.pop();

            ans.push_back({point[1], point[2]});
        }
        return ans;
    }
};
