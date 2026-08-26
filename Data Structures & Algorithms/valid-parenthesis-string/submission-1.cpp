class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                left.push(i);
            else if(s[i] == '*')
                star.push(i);
            else
            {
                if(left.empty())
                {
                    if(star.empty())
                        return false;
                    else
                        star.pop();
                }
                else
                    left.pop();
            }
        }
        while(!left.empty())
        {
            if(star.empty())
                return false;
            
            if(star.top() < left.top())
                return false;
            
            star.pop();
            left.pop();
        }
        return true;
    }
};
