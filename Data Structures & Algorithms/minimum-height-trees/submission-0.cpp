class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    void bfs(int node)
    {
        queue<pair<int,int>> q;
        vector<int> vis(ans.size(), 0);

        q.push({node, 0});
        vis[node] = 1;
        int answer = 0;
        while(!q.empty())
        {
            auto [child, height] = q.front();
            q.pop();

            answer = max(answer, height);
            for(auto nod : adj[child])
            {
                if(vis[nod])
                    continue;

                q.push({nod, height+1});
                vis[nod] = 1;
            }
        }

        ans[node] = answer;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        ans.resize(n, INT_MAX);
        adj.resize(n);
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < n; i++)
            bfs(i);

        int mini = *min_element(ans.begin(), ans.end());
        vector<int> ninjer;
        for(int i = 0; i < n; i++)
            if(ans[i] == mini)
                ninjer.push_back(i);

        return ninjer;
    }
};