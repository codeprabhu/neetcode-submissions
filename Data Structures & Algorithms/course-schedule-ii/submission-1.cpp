class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for(int i = 0; i < prereq.size(); i++)
        {
            int x = prereq[i][0], y = prereq[i][1];
            adj[y].push_back(x);
            indeg[x]++;
        }

        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indeg[i])
                continue;
            
            q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);
            
            for(auto child: adj[node])
            {
                indeg[child]--;
                if(indeg[child] == 0)
                    q.push(child);
            }
        }

        if(ans.size() != n)
            return {};
        return ans;
    }
};
