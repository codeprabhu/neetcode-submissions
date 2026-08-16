class DSU{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }    

    int find(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if(x == y)
            return;

        if(size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        unordered_map<string, int> mp;
        DSU dsu(a.size());
        for(int i = 0; i < a.size(); i++)
        {
            for(int j = 1; j < a[i].size(); j++)
            {
                string email = a[i][j];
                if(mp.count(email))
                    dsu.unite(i, mp[email]);
                else 
                    mp[email] = i;
            }
        } 
        unordered_map<int, set<string>> group;
        for(auto [email, name]: mp)
        {
            int root = dsu.find(name);
            group[root].insert(email);
        }

        vector<vector<string>> ans;
        for(auto [root, emails]: group)
        {
            vector<string> cur;
            cur.push_back(a[root][0]);
            for(auto email: emails)
                cur.push_back(email);
            ans.push_back(cur);
        }

        return ans;
    }
};