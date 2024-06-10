class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> arr(n);
        arr = heights;
        sort(arr.begin(),arr.end());
        int count = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]!=heights[i]) count++;
        }
        return count;
    }
};