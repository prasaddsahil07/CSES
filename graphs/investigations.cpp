#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void dijkstra(vector<vector<pair<ll, ll>>>& adjList, ll n, ll m){
    vector<ll> dist(n+1, LLONG_MAX);
    vector<ll> ways(n+1, 0);
    vector<ll> minNodeCntPath(n+1, 0);
    vector<ll> maxNodeCntPath(n+1, 0);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    dist[1] = 0;
    ways[1] = 1;
    minNodeCntPath[1] = 0;
    maxNodeCntPath[1] = 0;

    pq.push({0, 1});    // {distance, node}

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        ll dist_u = it.first;
        ll u = it.second;

        if(dist_u > dist[u])
            continue;   // if this distance is not the shortest, skip it

        for(auto& it: adjList[u]){
            ll v = it.first;
            ll w = it.second;

            if(dist[v] > dist[u]+w){    // if we found a shorter path to v
                dist[v] = dist[u]+w;
                ways[v] = ways[u];      // number of ways to reach v
                minNodeCntPath[v] = minNodeCntPath[u]+1;  // minimum number of nodes in the path to v
                maxNodeCntPath[v] = maxNodeCntPath[u]+1;  // maximum number of nodes in the path to v
                pq.push({dist[v], v});
            }
            else if(dist[v] == dist[u]+w){
                ways[v] = (ways[v] + ways[u]) % MOD;  // accumulate the number of ways to reach v
                minNodeCntPath[v] = min(minNodeCntPath[v], minNodeCntPath[u]+1);  // minimum number of nodes in the path to v
                maxNodeCntPath[v] = max(maxNodeCntPath[v], maxNodeCntPath[u]+1);  // maximum number of nodes in the path to v
            }
        }
    }

    cout<<dist[n]<<" "<<ways[n]<<" "<<minNodeCntPath[n]<<" "<<maxNodeCntPath[n]<<endl;
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<pair<ll, ll>>> adjList(n+1);
    for(int i=0; i<m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    dijkstra(adjList, n, m);
    return 0;
}
