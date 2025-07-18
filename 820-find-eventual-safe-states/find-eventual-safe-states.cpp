class Solution {
private:
    // Helper DFS function to detect cycles and mark safe nodes
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<int>& checkSafe, vector<vector<int>>& graph) {
        vis[node] = 1;         // Mark node as visited
        pathVis[node] = 1;     // Mark node as part of current DFS path
        for (auto nbr : graph[node]) {
            // If neighbor is not visited, explore it
            if (!vis[nbr]) {
                if (dfs(nbr, vis, pathVis, checkSafe, graph)) {
                    // If cycle is detected via neighbor, mark current node as unsafe
                    checkSafe[node] = 0;
                    return true;
                }
            }
            // If neighbor is already visited and part of current path → cycle
            else if (pathVis[nbr] == 1) {
                checkSafe[node] = 0;
                return true;
            }
        }
        pathVis[node] = 0;     // Backtrack: remove node from current DFS path
        checkSafe[node] = 1;   // No cycle from this node → it's safe
        return false;          // No cycle detected
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();                 // Number of nodes in the graph
        vector<int> vis(V, 0);                // Visited array
        vector<int> pathVis(V, 0);            // Current DFS path visited
        vector<int> checkSafe(V, 0);          // Marks if a node is safe (1) or not (0)
        vector<int> safeNodes;                // Stores the safe nodes
        // Run DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathVis, checkSafe, graph);
            }
        }
        // Collect all safe nodes
        for (int i = 0; i < V; i++) {
            if (checkSafe[i] == 1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
