#include <bits/stdc++.h>
using namespace std;

vector<int> shortest(int n, vector<pair<int, int>>& edges, int source) {
    // Adjacency list representation of the graph
    vector<vector<int>> adjList(n);
    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);  // Since the graph is undirected
    }
    
    // Distance array to keep track of shortest distances from source
    vector<int> distance(n, INT_MAX);
    queue<int> q;

    // Initialize
    distance[source] = 0;
    q.push(source);

    // Perform BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Explore all neighbors
        for (int neighbor : adjList[node]) {
            if (distance[neighbor] == INT_MAX) {  // Not visited yet
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> edges(m);

    // Read the edges
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int source;
    cin >> source;

    // Get shortest distances from source
    vector<int> distances = shortest(n, edges, source);

    // Print distances
    for (int i = 0; i < n; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": Distance INF" << endl;
        } else {
            cout << "Node " << i << ": Distance " << distances[i] << endl;
        }
    }

    return 0;
}
