class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++) {
            st.push(s[i]);
            if(st.size()>1) {
                if(st.top() == 'B') {
                    char ch = st.top();
                    st.pop();
                    if(st.top() == 'A') st.pop();
                    else st.push(ch);
                }
                else if(st.top() == 'D') {
                    char ch = st.top();
                    st.pop();
                    if(st.top() == 'C') st.pop();
                    else st.push(ch);
                }
            }
        }

        return st.size();
    }
};