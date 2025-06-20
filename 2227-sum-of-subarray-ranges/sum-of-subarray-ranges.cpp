class Solution {
  private:
    // finding previous smaller and equal element : 
    void pseeIdx(vector<int>& arr, vector<int>& psee, stack<int>& st) {
        for(int i=0; i<arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
    }
    
    // finding next smaller element :
    void nseIdx(vector<int>& arr, vector<int>& nse, stack<int>& st) {
        for(int i=arr.size()-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = (st.empty()) ? arr.size() : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
    }
    
    // finding previous greater and equal element : 
    void pgeeIdx(vector<int>& arr, vector<int>& pgee, stack<int>& st) {
        for(int i=0; i<arr.size(); i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pgee[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
    }
    
    // finding next greater element : 
    void ngeIdx(vector<int>& arr, vector<int>& nge, stack<int>& st) {
        for(int i=arr.size()-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = (st.empty()) ? arr.size() : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
    }

public:
    long long subArrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> psee(n), nse(n), pgee(n), nge(n);
        
        stack<int> st;
        pseeIdx(arr, psee, st);
        nseIdx(arr, nse, st);
        pgeeIdx(arr, pgee, st);
        ngeIdx(arr, nge, st);
        
        __int128 sumMin = 0, sumMax = 0;  // can store upto 128 bit numbers
        for (int i = 0; i < n; i++) {
            __int128 leftMin  = i - psee[i];
            __int128 rightMin = nse[i] - i;
            sumMin += leftMin * rightMin * arr[i];

            __int128 leftMax  = i - pgee[i];
            __int128 rightMax = nge[i] - i;
            sumMax += leftMax * rightMax * arr[i];
        }

        __int128 result = sumMax - sumMin;
        return (long long)result;  // C-like cast
    }
};