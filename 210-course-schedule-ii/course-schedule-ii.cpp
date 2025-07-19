class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        // Step 1: Create the adjacency list.
        // If course 'u' has a prerequisite 'v', we draw a directed 
        // edge from v to u (v -> u)
        vector<vector<int>> adjList(N);
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0]; // course to take
            int v = prerequisites[i][1]; // prerequisite course
            adjList[v].push_back(u);
        }
        // Step 2: Compute in-degree (number of incoming edges) for each node
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++) {
            for(auto nbr : adjList[i]) {
                indegree[nbr]++;
            }
        }
        // Step 3: Initialize a queue with all nodes having 
        // in-degree 0 (no prerequisites)
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        // Step 4: Perform BFS using Kahn's algorithm for Topological Sort
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // Decrease the in-degree of neighboring nodes
            for(auto nbr : adjList[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        // Step 5: If all nodes are processed, return the order; 
        // else return empty array (cycle detected if topo.size() != N)
        return (topo.size() == N) ? topo : vector<int>{};        
    }
};