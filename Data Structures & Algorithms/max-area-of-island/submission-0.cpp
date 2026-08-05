class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        int ans = 0;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!grid[i][j])
                    continue;
                if(vis[i][j])
                    continue;
                
                q.push({i, j});
                vis[i][j] = 1;
                int cur = 1;

                while(!q.empty())
                {
                    auto [x,y] = q.front();
                    q.pop();

                    for(int k = 0; k <= 3; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx >= n || ny >= m || nx < 0 || ny < 0)
                            continue;
                        if(!grid[nx][ny])
                            continue;
                        if(vis[nx][ny])
                            continue;

                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                        cur++;
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
