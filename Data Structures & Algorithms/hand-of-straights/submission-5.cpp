class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if(n%k != 0)
            return false;

        sort(hand.begin(), hand.end());
        map<int, int> mp;
        for(auto hands: hand)
            mp[hands]++;

        int turn = n/k;
        while(turn--)
        {
            int count = 0;
            vector<int> ans;
            for(auto it: mp)
            {
                if(count == k)
                    break;
                if(mp[it.first] == 0)
                    continue;
                
                ans.push_back(it.first);
                mp[it.first]--;

                count++;
            }
            if(ans.size() < k)
                return false;
            for(int i = 1; i < k; i++)
                if(ans[i] != ans[i-1]+1)
                    return false;
        }
        return true;
    }
};
