class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        vector<int> ans;
        int check = nums.size()/3;
        for(auto node: mp)
        {
            if(node.second > check)
                ans.push_back(node.first);
        }

        return ans;
    }
};