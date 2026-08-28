class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> reach(n, vector<int>(m, 0));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O')
            {
                queue<pair<int, int>> q;
                q.push({i,0});

                while(!q.empty())
                {
                    auto [x,y] = q.front();
                    q.pop();

                    reach[x][y] = 1;
                    for(int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(nx >= n || nx < 0 || ny >= m || ny < 0)
                            continue;
                        if(board[nx][ny] == 'X')
                            continue;
                        if(reach[nx][ny] == 1)
                            continue;

                        q.push({nx,ny});
                    }
                }
            }

            if(board[i][m-1] == 'O')
            {
                queue<pair<int, int>> q;
                q.push({i,m-1});

                while(!q.empty())
                {
                    auto [x,y] = q.front();
                    q.pop();

                    reach[x][y] = 1;
                    for(int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(nx >= n || nx < 0 || ny >= m || ny < 0)
                            continue;
                        if(board[nx][ny] == 'X')
                            continue;
                        if(reach[nx][ny] == 1)
                            continue;

                        q.push({nx,ny});
                    }
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(board[0][i] == 'O')
            {
                queue<pair<int, int>> q;
                q.push({0,i});

                while(!q.empty())
                {
                    auto [x,y] = q.front();
                    q.pop();

                    reach[x][y] = 1;
                    for(int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(nx >= n || nx < 0 || ny >= m || ny < 0)
                            continue;
                        if(board[nx][ny] == 'X')
                            continue;
                        if(reach[nx][ny] == 1)
                            continue;

                        q.push({nx,ny});
                    }
                }
            }

            if(board[n-1][i] == 'O')
            {
                queue<pair<int, int>> q;
                q.push({n-1, i});

                while(!q.empty())
                {
                    auto [x,y] = q.front();
                    q.pop();

                    reach[x][y] = 1;
                    for(int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(nx >= n || nx < 0 || ny >= m || ny < 0)
                            continue;
                        if(board[nx][ny] == 'X')
                            continue;
                        if(reach[nx][ny] == 1)
                            continue;

                        q.push({nx,ny});
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'X')
                    continue;
                if(reach[i][j])
                    continue;
                
                board[i][j] = 'X';
            }
        }
    }
};
