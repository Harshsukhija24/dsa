#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;  // Mark the current node as visited

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, node, adjList, visited)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}


bool detectCycle(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(n);  // Initialize the adjacency list

    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first); // Because the graph is undirected
    }

    vector<bool> visited(n, false);  // To keep track of visited nodes

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, -1, adjList, visited)) {
                return true;  // Cycle detected
            }
        }
    }
    return false;  // No cycle detected
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (detectCycle(n, edges)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
