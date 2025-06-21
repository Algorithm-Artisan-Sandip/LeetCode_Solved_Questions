// optimal : T.C: O(n), S.C: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        long long maxArea = 0;
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int poppedEl = heights[st.top()]; 
                st.pop();
                int pse = (st.empty()) ? -1 : st.top();  // the current top element is the previous smaller element of the popped element
                int nse = i;  // the current element in the array is the next smaller element of the popped element
                maxArea = max(maxArea, 1LL*poppedEl*(nse-pse-1));  // formula to find the max area
            }
            st.push(i);
        }

        // if for any element there is no next smaller element then the stack stil has one or more elements
        while(!st.empty()) {
            int poppedEl = heights[st.top()];
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            int nse = heights.size();
            maxArea = max(maxArea, 1LL*poppedEl*(nse-pse-1));
        }
        return maxArea;
    }
};