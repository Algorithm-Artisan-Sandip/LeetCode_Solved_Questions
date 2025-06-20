// Optimal : T.C: O(n), S.C: O(n)
class Solution {
private:
    // previous smaller element : 
    void pseIdx(vector<int>& pse, vector<int>& arr, stack<int>& st) {
        for(int i=0; i<arr.size(); i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
    }

    // next smaller OR EQUAL element : 
    void nseeIdx(vector<int>& nsee, vector<int>& arr, stack<int>& st) {
        for(int i=arr.size()-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nsee[i] = (st.empty()) ? arr.size() : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse(arr.size());
        vector<int> nsee(arr.size());
        stack<int> st;
        pseIdx(pse, arr, st);
        nseeIdx(nsee, arr, st);
        int total = 0;
        int mod = 1000000007;
        for(int i=0; i<arr.size(); i++) {
            int left = i-pse[i];
            int right = nsee[i]-i;
            total = (total + (1LL*left*right*arr[i]) % mod) % mod;
        }
        return total;
    }
};