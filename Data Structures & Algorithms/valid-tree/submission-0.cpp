class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;

        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0], y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> vis(n, -1);
        queue<int> q;
        vis[0] = 1;
        q.push(0);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto child: adj[node])
            {
                if(vis[child] == -1)
                {
                    q.push(child);
                    vis[child] = 1-vis[node];
                }
                else
                {
                    if(vis[child] == vis[node])
                        return false;
                }
            }
        }

        for(auto node: vis)
        {
            if(node == -1)
                return false;
        }

        return true;
    }
};
