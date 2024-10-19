#include <bits/stdc++.h>
using namespace std;

// Depth-First Search function to explore the island
void dfs(vector<vector<char>> &grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();

    // Base case: If the cell is out of bounds or is water ('0'), return
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') {
        return;
    }

    // Mark the current cell as visited by changing '1' to '0'
    grid[i][j] = '0';

    // Explore the neighboring cells (down, up, right, left)
    dfs(grid, i + 1, j);  // down
    dfs(grid, i - 1, j);  // up
    dfs(grid, i, j + 1);  // right
    dfs(grid, i, j - 1);  // left
}

// Function to count the number of islands
int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    int n = grid.size();
    int m = grid[0].size();
    int num_islands = 0;

    // Traverse the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If a '1' is found, it indicates a new island
            if (grid[i][j] == '1') {
                dfs(grid, i, j);  // Explore the entire island
                num_islands++;    // Increment the island count
            }
        }
    }

    return num_islands;
}

int main() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    cout << "Enter the grid (only '1' for land and '0' for water):" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
