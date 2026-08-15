class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qu) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < pre.size(); i++)
        {
            int x = pre[i][0], y = pre[i][1];
            adj[x].push_back(y);
            indeg[y]++;
        }

        vector<unordered_set<int>> anc(n);
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(!indeg[i])
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto child: adj[node])
            {
                anc[child].insert(node);
                for(int ancestor: anc[node])
                    anc[child].insert(ancestor);

                indeg[child]--;
                if(!indeg[child])
                    q.push(child);
            }
        }

        vector<bool> ans;
        for(int i = 0; i < qu.size(); i++)
        {
            int child = qu[i][1];
            int node = qu[i][0];

            if(anc[child].find(node) == anc[child].end())
                ans.push_back(false);
            else 
                ans.push_back(true);
        }
        
        return ans;

    }
};