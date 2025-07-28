#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> dist(2501, LLONG_MAX), vis(2501, 0);
vector<vector<ll>> adjrev(2501);

void dfs(ll node, vector<ll>& reachable) {
    if (vis[node]) return;
    vis[node] = 1;
    reachable.push_back(node);
    for (auto &neighbour : adjrev[node]) {
        dfs(neighbour, reachable);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<pair<ll, ll>, ll>> edges(m);

    // Input edges and initialize adj list
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {{u, v}, -w};
        adj[u].push_back({v, -w});
    }

    dist[1] = 0;

    // Bellman-Ford
    for (ll i = 0; i < n - 1; i++) {
        for (auto& e : edges) {
            ll u = e.first.first, v = e.first.second, w = e.second;
            if (dist[u] != LLONG_MAX) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    // Negative cycle detection
    set<ll> affectedNodes;
    for (auto& e : edges) {
        ll u = e.first.first, v = e.first.second, w = e.second;
        if (dist[u] != LLONG_MAX) {
            ll prev = dist[v];
            dist[v] = min(dist[v], dist[u] + w);
            if (dist[v] != prev) affectedNodes.insert(v);
        }
    }

    // Reverse graph for reachable nodes
    for (auto& e : edges) {
        swap(e.first.first, e.first.second);
    }
    for (auto& e : edges) {
        adjrev[e.first.first].push_back(e.first.second);
    }

    // DFS to find reachable nodes from the destination
    vector<ll> reachable;
    dfs(n, reachable);

    // Check if any affected node is reachable
    bool valid = true;
    for (auto& node : reachable) {
        if (affectedNodes.count(node)) {
            valid = false;
            break;
        }
    }

    // Output result
    if (valid && dist[n] != LLONG_MAX) {
        cout << -dist[n] << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}
