class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0, l = 0, r = n-1;

        while(l < r)
        {
            int area =  min(heights[l], heights[r])* (r-l);
            ans = max(area, ans);

            if(heights[r] > heights[l])
                l++;
            else if(heights[l] > heights[r])
                r--;
            else
            {
                l++;
                r--;
            }
        }

        return ans;
    }
};
