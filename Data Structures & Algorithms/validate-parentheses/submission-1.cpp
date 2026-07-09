class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(c == '{' || c == '[' || c == '(')
                st.push(c);
            else
            {
                if(st.size() == 0)
                    return false;
                char d = st.top();
                if(c == '}')
                {
                    if(d == '{')
                        st.pop();
                    else
                        return false;
                }
                else if(c == ')')
                {
                    if(d == '(')
                        st.pop();
                    else 
                        return false;
                }
                else 
                {
                    if(d == '[')
                        st.pop();
                    else 
                        return false;
                }
            }
        }
        if(st.size())
            return false;
        return true;
    }
};
