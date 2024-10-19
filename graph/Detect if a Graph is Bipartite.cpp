#include <bits/stdc++.h>
using namespace std;

bool bipartite(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(n);
    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }

    vector<int> color(n, -1);  // Initialize color array

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {  // If not colored, perform BFS
            queue<int> q;
            q.push(i);
            color[i] = 0;  // Start coloring with color 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adjList[node]) {
                    if (color[neighbor] == -1) {  // If not colored
                        color[neighbor] = 1 - color[node];  // Alternate color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;  // All components checked and no conflicts found
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (bipartite(n, edges)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
