#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<tuple<int, int, int>>& edges, int source) {
    vector<vector<pair<int, int>>> adjList(n);
    
    // Build the adjacency list
    for (auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w); // If the graph is undirected; remove this line for directed graph
    }

    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    // Priority queue to store (distance, node) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip if the distance is not up-to-date
        if (dist > distance[node]) {
            continue;
        }

        // Traverse all adjacent nodes
        for (auto& neighbor : adjList[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (distance[node] + weight < distance[nextNode]) {
                distance[nextNode] = distance[node] + weight;
                pq.emplace(distance[nextNode], nextNode);
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);

    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = make_tuple(u, v, w);
    }

    int source;
    cin >> source;

    vector<int> result = dijkstra(n, edges, source);

    // Output the shortest distances
    for (int dist : result) {
        if (dist == INT_MAX) {
            cout << "INF "; // Infinite distance
        } else {
            cout << dist << " ";
        }
    }
    cout << endl;

    return 0;
}
