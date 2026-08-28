class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            int distance = node[0], x = node[1], y = node[2];
            if(distance > dist[x][y])
                continue;

            if(x == n-1 && y == m-1)
                return distance;
            for(int i = 0; i < 4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx >= n || ny >= m || ny < 0 || nx < 0)
                    continue;

                if(max(abs(heights[nx][ny]-heights[x][y]), distance) < dist[nx][ny])
                {
                    dist[nx][ny] = max(abs(heights[nx][ny]-heights[x][y]), distance);
                    pq.push({dist[nx][ny], nx, ny});
                }
                
            }
        }
        return -1;
    }
};