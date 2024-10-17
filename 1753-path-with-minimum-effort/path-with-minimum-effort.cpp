class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));

        diff[0][0] = 0; // source node
        int col[] = {0, +1, 0, -1};  // for up, right, down, left
        int row[] = {-1, 0, +1, 0};  // for up, right, down, left

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto topNode = pq.top();
            int currDiff = topNode.first;
            int r = topNode.second.first;
            int c = topNode.second.second;
            pq.pop();

            for(int i=0; i<4; i++) {
                int newRow = r + row[i];
                int newCol = c + col[i];

                if(newRow < n && newCol < m && newRow >= 0 && newCol >= 0) {
                    int newDiff = max(currDiff, abs(heights[r][c]-heights[newRow][newCol]));
                    if(newDiff < diff[newRow][newCol]) {
                        diff[newRow][newCol] = newDiff;
                        pq.push({newDiff, {newRow, newCol}});
                    }
                }
            }
        }

        return diff[n-1][m-1];
    }
};