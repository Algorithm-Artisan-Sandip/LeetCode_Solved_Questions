class Solution {
private:
    void dfs(int node, int end, vector<int>& ans, vector<vector<int>>& finalAns
             , vector<vector<int>>& graph) {
        ans.push_back(node);
        if(node == end) {
            finalAns.push_back(ans);
            ans.pop_back();
            return;
        }
        else {
            for(auto nbr : graph[node]) {
                dfs(nbr, end, ans, finalAns, graph);
            }
        }
        ans.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        dfs(0, graph.size()-1, ans, finalAns, graph);
        return finalAns;
    }
};