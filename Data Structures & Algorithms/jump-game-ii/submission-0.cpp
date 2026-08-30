class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
            
        queue<pair<int,int>> q;
        q.push({0, 0});

        vector<int> vis(n, 0);
        vis[0] = 1;

        while(!q.empty())
        {
            auto [node, turn] = q.front();
            q.pop();

            if(node == n-1)
                return turn;
            
            for(int i = 1; i <= nums[node]; i++)
            {
                int next = i+node;
                if(next >= n)
                    continue;

                if(vis[next])
                    continue;

                q.push({i+node, turn+1});
                vis[i+node] = 1;
            }
        }

        return -1;
    }
};
