class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";
        for(int i = 0; i < n; i++)
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                str += s[i] >= 'a'? s[i] : s[i]+32;

        n = str.size();
        for(int i = 0; i <= (n+1)/2; i++)
            if(str[i] != str[n-i-1])
                 return false;
        return true;

    }
};
