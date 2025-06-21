// Approach 1 : T.C: O(5n), S.C: O(4n)
class Solution {
private:
    void findPse(vector<int>& pse, vector<int>& heights, int size) {
        stack<int> st;
        for(int i=0; i<size; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }
    void findNse(vector<int>& nse, vector<int>& heights, int size) {
        stack<int> st;
        for(int i=size-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = (st.empty()) ? size : st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> pse(size), nse(size);
        findPse(pse, heights, size);
        findNse(nse, heights, size);
        int maxi = INT_MIN;
        for(int i=0; i<size; i++) {
            maxi = max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};