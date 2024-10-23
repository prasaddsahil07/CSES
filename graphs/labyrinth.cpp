#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<char> dirChar = {'U', 'R', 'D', 'L'};

bool isValid(int i, int j, vector<string>& map, vector<vector<bool>>& vis) {
    int n = map.size();
    int m = map[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || map[i][j] == '#' || vis[i][j]) {
        return false;
    }
    return true;
}

void BFS(vector<string>& map, vector<vector<bool>>& vis, int i, int j) {
    int n = map.size();
    int m = map[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[i][j] = 0;

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int x = it.first, y = it.second;

        for (int d = 0; d < 4; d++) {
            int new_i = x + directions[d].first;
            int new_j = y + directions[d].second;

            if (isValid(new_i, new_j, map, vis)) {
                vis[new_i][new_j] = true;
                q.push({new_i, new_j});
                parent[new_i][new_j] = {x, y};
                dist[new_i][new_j] = dist[x][y] + 1;
                
                if (map[new_i][new_j] == 'B') {
                    cout << "YES" << endl;
                    cout << dist[new_i][new_j] << endl;
                    string path;
                    int cur_i = new_i, cur_j = new_j;

                    while (parent[cur_i][cur_j] != make_pair(-1, -1)) {
                        int prev_i = parent[cur_i][cur_j].first;
                        int prev_j = parent[cur_i][cur_j].second;

                        for (int k = 0; k < 4; k++) {
                            if (prev_i + directions[k].first == cur_i && prev_j + directions[k].second == cur_j) {
                                path.push_back(dirChar[k]);
                                break;
                            }
                        }

                        cur_i = prev_i;
                        cur_j = prev_j;
                    }
                    reverse(path.begin(), path.end());
                    cout << path << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

void labyrinth(vector<string>& map) {
    int n = map.size();
    int m = map[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && map[i][j] == 'A') {
                BFS(map, vis, i, j);
                return;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    labyrinth(map);
    return 0;
}
