#include <bits/stdc++.h>
using namespace std;

bool DFS(map<int, vector<int>>& adj, vector<int>& color, int node, int c) {
    color[node] = c;
    for (auto& ngbr : adj[node]) {
        if (color[ngbr] == -1) {
            if (!DFS(adj, color, ngbr, 1 - c)) {
                return false;
            }
        } 
        else if (color[ngbr] == color[node]) {
            return false;
        }
    }
    return true;
}

void buildingTeams(map<int, vector<int>>& adj, int n) {
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!DFS(adj, color, i, 0)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] + 1 << " "; 
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    buildingTeams(adj, n);
    return 0;
}
