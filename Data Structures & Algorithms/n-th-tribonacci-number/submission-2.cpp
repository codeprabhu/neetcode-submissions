class Solution {
public:

    int tribonacci(int n) {
        if(n == 0)
            return 0;
        
        int x = 0, y = 1, z = 1;
        for(int i = 0; i < n-2; i++)
        {
            int ans = x+y+z;
            x = y;
            y = z; 
            z = ans;
        }
        return z;
    }
};