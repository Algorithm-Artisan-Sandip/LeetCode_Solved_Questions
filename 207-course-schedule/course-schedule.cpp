class Solution {
private : 
    void topoSort(int n, vector<int>& topoOrder, unordered_map<int, list<int>>& adjList) {
        queue<int> q;
        vector<int> indegree(n, 0);

        // sotring indegrees : 
        for(auto node : adjList) {
            for(auto nbr : node.second) {
                indegree[nbr]++;
            }
        }

        // storing the nodes with zero indegree : 
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // actual logic of bfs : 
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for(auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        for(vector<int> it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u);  // as v course must be taken before u so the edge is from v to u 
        }

        vector<int> topoOrder;
        topoSort(numCourses, topoOrder, adjList);

        if(topoOrder.size() == numCourses) return true;
        else return false;
    }
};