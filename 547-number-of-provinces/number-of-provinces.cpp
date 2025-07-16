class Solution {
private:
    // DFS to explore all cities in a single province
    void dfs(int node, vector<vector<int>>& isConnected, 
             vector<int>& vis, int v) {
        vis[node] = 1;  // Mark current city as visited

        // Explore all directly connected cities
        for (int i = 0; i < v; i++) {
            if (isConnected[node][i] == 1 && !vis[i]) {
                dfs(i, isConnected, vis, v);  // Visit the neighbor city
            }
        }        
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();        // Total number of cities
        vector<int> vis(v, 0);             // Visited array
        int comp = 0;                      // Number of provinces

        // Traverse each city
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                comp++;                    // Found a new province
                dfs(i, isConnected, vis, v); // Visit all cities in this province
            }
        }

        return comp;  // Return the total number of provinces
    }
};
