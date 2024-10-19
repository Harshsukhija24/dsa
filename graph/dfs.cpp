#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& dfsOrder) {
    visited[node] = true;           
    dfsOrder.push_back(node);      

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adjList, visited, dfsOrder);
        }
    }
}

vector<int> dfs(int n, vector<pair<int, int>>& edges, int source) {
    vector<vector<int>> adjList(n); 

    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first); 
    }

    vector<int> dfsOrder;             
    vector<bool> visited(n, false);   

    dfsUtil(source, adjList, visited, dfsOrder);

    return dfsOrder;
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

    vector<int> result = dfs(n, edges, source);  

    for (int node : result) {
        cout << node << " ";
    }

    cout << endl;
    return 0;
}
