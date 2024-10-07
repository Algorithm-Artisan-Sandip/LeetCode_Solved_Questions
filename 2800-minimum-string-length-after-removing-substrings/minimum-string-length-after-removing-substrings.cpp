class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        for(auto ch : s) {
            if(!st.empty()) {
                if((ch == 'B' && st.top() == 'A') || (ch == 'D' && st.top() == 'C')) {
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }

        return st.size();
    }
};