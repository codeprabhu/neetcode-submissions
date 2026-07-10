class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j])
                    continue;
                if(grid[i][j] == '0')
                    continue;

                q.push({i,j});
                cout << i << " " << j << "\n";
                    count++;

                while(!q.empty())
                {
                    auto [x,y] = q.front();
                    q.pop();

                    if(x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if(vis[x][y])
                        continue;
                    if(grid[x][y] == '0')
                        continue;
                    
                    vis[x][y] = 1;
                    q.push({x+1, y});
                    q.push({x-1, y});
                    q.push({x, y-1});
                    q.push({x, y+1});
                }
            }
        }
        return count;
    }
};
