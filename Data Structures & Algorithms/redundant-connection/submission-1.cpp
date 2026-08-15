class dsu
{
    public:
    vector<int> parent;
    vector<int> size;

    dsu(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);

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
            swap(x,y);
        
        parent[y] = x;
        size[x] += size[y];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dsu ninjer(n);
        
        for(auto edge: edges)
        {
            int x = edge[0];
            int y = edge[1];

            if(ninjer.find(x) == ninjer.find(y))
                return {x,y};
            
            ninjer.unite(x,y);
        }

        return {};
    }
};
