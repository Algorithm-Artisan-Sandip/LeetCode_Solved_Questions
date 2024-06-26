class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> st;
        for(char ch : s) {
            if(ch == '(') st.push(ch);
            else {
                if(st.empty()) {
                    st.push(ch);
                    continue;
                }
                
                if(ch == ')' && st.top() != '(') {
                    st.push(ch); count++;
                }
                if(ch == ')' && st.top() == '(') st.pop();
            }
        }
        if(st.size() > count) return st.size();
        else return count;
    }
};