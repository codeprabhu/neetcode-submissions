class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            deg[edge[0]]++;
            deg[edge[1]]++;
        }

        if (n == 1)
            return {0};

        queue<int> q;

        for (int i = 0; i < n; i++)
            if (deg[i] == 1)
                q.push(i);

        int remaining = n;

        while (remaining > 2)
        {
            int sz = q.size();
            remaining -= sz;

            while (sz--)
            {
                int node = q.front();
                q.pop();

                for (int nei : adj[node])
                {
                    deg[nei]--;

                    if (deg[nei] == 1)
                        q.push(nei);
                }
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};