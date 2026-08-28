class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        int m = target.size();
        unordered_map<string, int> mp;
        for(string deadend: deadends)
        {
            if(deadend == "0000")
                return -1;

            mp[deadend]++;
        }   
        if(target == "0000")
            return 0;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_map<string, int> seen;
        while(!q.empty())
        {
            auto [code, turn] = q.front();
            q.pop();

            if(code == target)
                return turn;

            for(int i = 0; i < m; i++)
            {
                string newer = code;
                if(newer[i] == '0')
                    newer[i] = '9';
                else
                    newer[i] -= 1;

                if(seen[newer])
                    continue;
                if(mp[newer])
                    continue;
                    
                q.push({newer, turn+1});
                seen[newer]++;
            }

            for(int i = 0; i < m; i++)
            {
                string newer = code;
                if(newer[i] == '9')
                    newer[i] = '0';
                else
                    newer[i] += 1;

                if(seen[newer])
                    continue;
                if(mp[newer])
                    continue;

                q.push({newer, turn+1});
                seen[newer]++;
            }
        }

        return -1;
    }
};