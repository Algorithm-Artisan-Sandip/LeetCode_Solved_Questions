class Solution {
private:
    void bfs(int n, int m, int sr, int sc, vector<vector<int>>& image, int color) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int original = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr, sc});
        visited[sr][sc] = true;

        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};

        while(!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int r = frontNode.first;
            int c = frontNode.second;

            for(int i=0; i<4; i++) {
                int newRow = r + row[i];
                int newCol = c + col[i];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && image[newRow][newCol] == original && !visited[newRow][newCol]) {
                   visited[newRow][newCol] = true;
                   image[newRow][newCol] = color;
                   q.push({newRow, newCol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        bfs(n, m, sr, sc, image, color);

        return image;
    }
};