class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                    q.push({{i,j},0});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int x = node.first.first;
            int y = node.first.second;
            int time = node.second;
            //cout << x << y << " " << time << "\n"; 
            for(int i = 0; i < 4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx >= n || ny >= m || nx < 0 || ny < 0)
                    continue;
                if(vis[nx][ny])
                    continue;
                if(grid[nx][ny] == 2 || !grid[nx][ny])
                    continue;

                q.push({{nx,ny}, time+1});
                fresh--;
                ans = max(ans, time+1);
                vis[nx][ny] = 1;
            }
        }
        if(fresh != 0)
            return -1;
        return ans;
    }
};
