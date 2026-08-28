class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight: flights)
        {
            int x = flight[0], y = flight[1];
            int price = flight[2];
            adj[x].push_back({y, price});
        }

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, src});

        while(!pq.empty())
        {
            auto stuff = pq.top();
            pq.pop();

            int dih = stuff[0];
            int node = stuff[2];
            int turn = stuff[1];

            if(dih > dist[node][turn])
                continue;
            if(turn > k+1)
                continue;
            if(node == dst)
                return dih;

            for(auto [child, distance]: adj[node])
            {
                if(turn > k)
                    continue;
                if(dih + distance < dist[child][turn+1])
                {
                    dist[child][turn+1] = dih + distance;
                    pq.push({dist[child][turn+1], turn+1, child});
                }
            }
        }
        return -1;
    }
};
