class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        unordered_map<string, int> dict;
        for(string word: words)
            dict[word]++;

        queue<pair<string, int>> q;
        q.push({begin, 1});
        set<string> vis;
        vis.insert(begin);

        while(!q.empty())
        {
            auto [node, turn] = q.front();
            q.pop();
            
            if(node == end)
                return turn;
            for(int j = 0; j < node.size(); j++)
            {
                for(int i = 0; i < 26; i++)
                {
                    string word = node;
                    if(word[j] == 'a'+i)
                        continue;

                    word[j] = i+'a';

                    if(vis.find(word) != vis.end())
                        continue;
                    if(!dict[word])
                        continue;
                    
                    q.push({word, turn+1});
                    vis.insert(word);
                }
            }
        }

        return 0;
    }
};
