#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<char>> ans;

bool isValid(int i, int j, char c) {
    // Check adjacent cells
    if (i > 0 && ans[i-1][j] == c) return false;
    if (i < n-1 && ans[i+1][j] == c) return false;
    if (j > 0 && ans[i][j-1] == c) return false;
    if (j < m-1 && ans[i][j+1] == c) return false;
    return true;
}

bool solve(int i, int j) {
    if (i == n) return true; // Reached end of grid
    if (j == m) return solve(i+1, 0); // Move to next row

    // Try each character A, B, C, D
    for (char c : {'A', 'B', 'C', 'D'}) {
        if (c != grid[i][j] && isValid(i, j, c)) { // Different from original and valid
            ans[i][j] = c;
            if (solve(i, j+1)) return true;
            ans[i][j] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    ans.assign(n, vector<char>(m, 0));
    
    // Read input grid
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Try to solve
    if (solve(0, 0)) {
        // Print solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}