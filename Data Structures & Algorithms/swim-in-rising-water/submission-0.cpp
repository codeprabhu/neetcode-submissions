class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({dist[0][0], 0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty())
        {
            auto stuff = pq.top();
            pq.pop();

            int x = stuff[1], y = stuff[2];
            int distance = stuff[0];

            for(int i = 0; i < 4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx >= n || ny >= m || nx < 0 || ny < 0)
                    continue;
                int dih = max(distance, grid[nx][ny]);
                if(dih < dist[nx][ny])
                {
                    dist[nx][ny] = dih;
                    pq.push({dih, nx, ny});
                }
            }
        }

        return dist[n-1][m-1];

    }
};
