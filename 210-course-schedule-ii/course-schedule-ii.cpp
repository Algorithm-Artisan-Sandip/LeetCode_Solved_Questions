class Solution {
public:
    void topoSort(int n, vector<int>& topoOrder, unordered_map<int, list<int>>& adjList) {
        queue<int> q;
        vector<int> indegree(n, 0);

        // storing the indegrees : 
        for(auto it : adjList) {
            for(auto nbr : it.second) {
                indegree[nbr]++;
            }
        }

        // storing the zero indegree nodes in the queue : 
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // actual bfs logic : 
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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        for(vector<int> it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u);
        }

        vector<int> topoOrder;
        topoSort(numCourses, topoOrder, adjList);

        if(topoOrder.size() == numCourses) return topoOrder;
        else return {};
    }
};