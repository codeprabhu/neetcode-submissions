class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        queue<int> q;
        int count = 0;

        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                continue;
            
            q.push(i);
            vis[i]++;
            count++;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(auto it: adj[node])
                {
                    if(vis[it])
                        continue;

                    q.push(it);
                    vis[it]++;
                }
            }   
        }
        return count;
    }
};
