class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int count = 0;
        int i=0, j=s.size();
        while(i<j) {
            if(s[i] == '[') {
                st.push('[');
            }
            else {
                if(!st.empty()) {
                    st.pop();
                }
                else count++;
            }
            i++;
        }
        return (count+1)/2;
    }
};