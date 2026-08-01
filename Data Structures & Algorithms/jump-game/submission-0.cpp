class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        
        int farthest = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(farthest < i)
                return false;
            farthest = max(farthest, nums[i] + i);
        }
        return true;
    }
};
