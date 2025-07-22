class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Adjacency list to store graph in the form: node -> [(neighbour, weight)]
        vector<vector<pair<int, int>>> adjList(n);
        for(auto road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adjList[u].push_back({v, dist});
            adjList[v].push_back({u, dist});
        }
        // Use long long for distances
        using ll = long long;
        // Min-heap priority queue to get the node with minimum distance at top
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0}); // {distance_from_source, node}
        // Distance vector to track shortest distance to each node
        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0; // Distance to source is 0
        // Ways vector to track number of ways to reach each node via shortest path
        vector<int> ways(n, 0);
        ways[0] = 1; // There's one way to reach the source: by starting there
        int mod = 1e9 + 7; // To handle large numbers
        // Dijkstra's algorithm with path counting
        while(!pq.empty()) {
            ll currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(auto nbr : adjList[currNode]) {
                int adjNode = nbr.first;
                int adjDist = nbr.second;
                // If a shorter path is found
                if(currDist + adjDist < dist[adjNode]) {
                    dist[adjNode] = currDist + adjDist;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[currNode]; // Start a new count from current node
                }
                // If another path with the same minimum distance is found
                else if(currDist + adjDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[currNode]) % mod;
                }
            }
        }
        // Return the number of ways to reach the destination node (n-1)
        return ways[n - 1] % mod;
    }
};
