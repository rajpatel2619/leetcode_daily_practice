class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        
        // Build adjacency list
        for (auto &road : roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Min-cost array (Dijkstra's Algorithm)
        vector<long long> minCost(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        // Min heap {cost, node} for Dijkstra
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Start from node 0
        minCost[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            // If the cost is outdated, skip it
            if (cost > minCost[node]) continue;
            
            for (auto &[neighbor, weight] : graph[node]) {
                long long newCost = cost + weight;
                
                // If a new shorter path is found
                if (newCost < minCost[neighbor]) {
                    minCost[neighbor] = newCost;
                    ways[neighbor] = ways[node];  // New shortest path found
                    pq.push({newCost, neighbor});
                }
                // If the same shortest path cost is found, add ways
                else if (newCost == minCost[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n - 1];  // Number of ways to reach node n-1 with shortest path
    }
};
