class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        st.push(n); // sentinel value for the last element

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != n && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> previousSmaller(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        st.push(-1); // sentinel value for the first element

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;

        vector<int> next = nextSmaller(heights);
        vector<int> prev = previousSmaller(heights);
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int width;
            if (next[i] == heights.size()) {
                width = heights.size() - prev[i] - 1;
            } else {
                width = next[i] - prev[i] - 1;
            }
            int length = heights[i];
            int area = width * length;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
