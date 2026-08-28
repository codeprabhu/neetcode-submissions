class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++)
        {
            int x = times[i][0], y = times[i][1], dist = times[i][2];
            adj[x].push_back({y,dist});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty())
        {
            auto [dih, node] = pq.top();
            pq.pop();

            for(auto [child, wt]: adj[node])
            {
                if(dist[node] + wt < dist[child])
                {
                    dist[child] = dist[node]+wt;
                    pq.push({dist[child], child});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i == k)
                continue;

            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
