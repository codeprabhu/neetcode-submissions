class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        int farthest = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(farthest < i)
                return false;
            
            farthest = max(nums[i]+i, farthest);
        }

        return true;
    }
};
