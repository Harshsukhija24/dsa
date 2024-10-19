#include <bits/stdc++.h>
using namespace std;

// Utility function for DFS and storing the topological order
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, topoStack);
        }
    }
    topoStack.push(node); // Push the node onto the stack after visiting all its neighbors
}

// Function to perform topological sort
vector<int> topo(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(n);

    for (auto& edge : edges) {
        adjList[edge.first].push_back(edge.second);
    }

    vector<bool> visited(n, false);
    stack<int> topoStack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited, topoStack);
        }
    }

    // Extract the topological order from the stack
    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }
    return topoOrder;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> result = topo(n, edges);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
