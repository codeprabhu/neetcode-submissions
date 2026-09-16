class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lmax = height[l], rmax = height[r];
        int ans = 0;
        while(l < r)
        {
            if(height[l] > lmax)
                lmax = height[l];
            if(height[r] > rmax)
                rmax = height[r];

            if(height[l] < height[r])
            {
                ans += lmax - height[l];
                l++;
            }
            else
            {
                ans += rmax - height[r];
                r--;
            }   
        }
        return ans;
    }
};
