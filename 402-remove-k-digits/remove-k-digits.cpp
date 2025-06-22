// Optimial : T.C: O(3*n) + O(k), S.C: O(2*n) 
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0; i<num.size(); i++) {
            while(!st.empty() && k > 0 && (st.top()-'0') > (num[i]-'0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // if still k is not zero : 
        while(k--) {
            st.pop();
        }
        // if now the stack is empty : 
        if(st.empty()) return "0";
        // forming the answer : 
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        // if there is any leading zeros : 
        while(result.size() && result.back() == '0') result.pop_back();
        // if the result is empty : 
        if(!result.size()) return "0";
        // reversing the result to get the correct order of the answer string : 
        reverse(result.begin(), result.end());
        return result;
    }
};