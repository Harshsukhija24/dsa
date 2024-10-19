#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<pair<int, int>>& edges, int source) {
    // Corrected the type of adjList to a vector of vectors
    vector<vector<int>> adjList(n);

    // Building the adjacency list from the edges
    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first); // Since the graph is undirected
    }

    // BFS traversal
    vector<int> bfsOrder;          // Stores the BFS traversal order
    vector<bool> visited(n, false); // To keep track of visited nodes
    queue<int> q;

    // Start BFS from the source node
    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsOrder.push_back(node);

        // Traverse all adjacent nodes
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsOrder;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int source;
    cin >> source;

    vector<int> result = bfs(n, edges, source);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
