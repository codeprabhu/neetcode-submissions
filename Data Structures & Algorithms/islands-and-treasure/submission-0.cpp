class Solution {
public:
    const int inf = INT_MAX;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    q.push({{i,j},1});
            }
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int x = node.first.first;
            int y = node.first.second;
            int dist = node.second;

            for(int i = 0; i < 4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx >= n || ny >= m || nx < 0 || ny < 0)
                    continue;                
                if(vis[nx][ny])
                    continue;
                if(grid[nx][ny] == -1 || !grid[nx][ny])
                    continue;

                grid[nx][ny] = dist;
                q.push({{nx,ny},dist+1});
                vis[nx][ny] = 1;
            }
        }
    }
};
