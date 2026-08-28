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

    int find(int n)
    {
        if(parent[n] == n)
            return n;

        return parent[n] = find(parent[n]);
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int cost = abs(x1-x2)+abs(y1-y2);

                edges.push_back({cost,{i, j}});
            }
        }

        sort(edges.begin(), edges.end());
        DSU dsu(n);

        int ans = 0, used = 0;
        for(auto edge: edges)
        {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if(dsu.find(u) == dsu.find(v))
                continue;

            dsu.unite(u, v);
            ans += cost;
            used++;
            
            if(used == n-1)
                break;
        }

        return ans;
    }
};
