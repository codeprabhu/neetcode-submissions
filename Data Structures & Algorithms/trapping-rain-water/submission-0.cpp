class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() -1;
        int leftmax = height[l], rightmax = height[r];
        int ans = 0;
        while(l < r)
        {
            int h = min(leftmax, rightmax);
            if(leftmax < rightmax)
            {
                if(h-height[l] > 0)
                    ans += h-height[l];
                l++;
            }
            else 
            {
                if(h - height[r] > 0)
                    ans += h-height[r];
                r--;
            }
            
            leftmax = max(leftmax, height[l]);
            rightmax = max(rightmax, height[r]);
        }

        return ans;
    }
};
