class Solution {
private:
    // DFS function to check if the graph can be colored using 2 colors
    // such that no two adjacent nodes have the same color
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
        // Traverse all adjacent nodes
        for(auto nbr : graph[node]) {
            // If the neighbor has not been colored, assign it the opposite color
            if(color[nbr] == -1) {
                color[nbr] = !color[node];
                if(dfs(nbr, color, graph) == false)
                    return false;
            }
            // If the neighbor has the same color as the current node, not bipartite
            if(color[nbr] == color[node]) {
                return false;
            }
        }
        return true; // No conflicts found, graph is bipartite from this component
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1); // Initialize all nodes as uncolored
        // Check each component of the graph (in case of disconnected components)
        for(int i = 0; i < v; i++) {
            if(color[i] == -1) {
                // If a component is not bipartite, return false
                color[i] = 0;
                if(!dfs(i, color, graph))
                    return false;
            }
        }
        return true; // All components are bipartite
    }
};
