class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(int i = 0; i < prereq.size(); i++)
        {
            int x = prereq[i][0], y = prereq[i][1];
            adj[y].push_back(x);
            indeg[x]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indeg[i] == 0)
                q.push(i);

        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            count++;
            cout << node << "\n";
            for(auto it: adj[node])
            {                
                indeg[it]--;
                if(indeg[it] == 0)
                    q.push(it);
            }
        }
        if(count != n)
            return false;
        else 
            return true;
    }
};