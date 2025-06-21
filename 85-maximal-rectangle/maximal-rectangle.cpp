// Optimal : Using largest Histogram Method
// T.C: O(n^2), S.C: O(n^2)
class Solution {
private:
    void computePrefixSum(vector<vector<char>>& matrix, vector<vector<int>>& prefixSum) {
        for(int j=0; j<matrix[0].size(); j++) {
            int sum = 0;
            for(int i=0; i<matrix.size(); i++) {
                if(matrix[i][j] == '1') sum++;
                else sum = 0;
                prefixSum[i][j] = sum;
            }
        }
    }

    int largestHistogram(vector<int> prefixSumRow) {
        stack<int> st;
        int ans = 0;
        for(int i=0; i<prefixSumRow.size(); i++) {
            while(!st.empty() && prefixSumRow[st.top()] > prefixSumRow[i]) {
                int poppedEl = prefixSumRow[st.top()];
                st.pop();
                int pse = (st.empty()) ? -1 : st.top();
                int nse = i;
                ans = max(ans, poppedEl*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            int poppedEl = prefixSumRow[st.top()];
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            int nse = prefixSumRow.size();
            ans = max(ans, poppedEl*(nse-pse-1));
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        computePrefixSum(matrix, prefixSum);
        for(int i=0; i<matrix.size(); i++) {
            maxArea = max(maxArea, largestHistogram(prefixSum[i]));
        }
        return maxArea;
    }
};