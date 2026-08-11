class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone: stones)
            pq.push(stone);

        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();

            if(pq.empty())
                return x;
            
            int y = pq.top();
            pq.pop();

            pq.push(abs(x-y));
        }

        return 0;
    }
};
