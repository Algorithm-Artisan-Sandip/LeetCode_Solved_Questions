class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;
        for(auto temp : logs) {
            if(temp[0] != '.') st.push(1);
            else if(temp[1]=='.' && !st.empty()) {
                st.pop();
            }
        }
        int count = 0;
        while(true) {
            if(st.empty()) {
                return count;
            }
            st.pop();
            count++;
        }
    }
};