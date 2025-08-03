#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bellmannFord(map<int, vector<pair<int, int>>>& adjList, int n, int m) {
    vector<ll> dist(n+1, 0);
    vector<ll> parent(n+1, -1);

    ll start = -1;

    // dist[1] = 0;

    for(int i=1; i<=n; i++){
        start = -1; // reset start  each iteration
        for (auto it : adjList) {
            ll u = it.first;
            for(auto p: it.second){
                ll v = p.first;
                ll w = p.second;
                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u]+w;
                    parent[v] = u;
                    if(i == n)
                        start = v; // detect cycle on nth iteration
                }
            }
        }
    }

    if(start == -1){
        cout<<"NO"<<endl;
        return;
    }

    // go back n steps to enter the cycle
    for(int i=0; i<n ; i++){
        start = parent[start];
    }

    vector<ll> cycle;
    // set<ll> visited;
    // ll v = start;

    // while (visited.find(v) == visited.end()) {
    //     visited.insert(v);
    //     cycle.push_back(v);
    //     v = parent[v];
    // }
    // cycle.push_back(v);
    for(ll curr = start; ; curr = parent[curr]){
        cycle.push_back(curr);
        if(curr == start && cycle.size() > 1)   break;
    }

    reverse(cycle.begin(), cycle.end());

    cout<<"YES"<<endl;
    for(ll c: cycle){
        cout<<c<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    map<int, vector<pair<int, int>>> adjList;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back({v, w});
    }
    bellmannFord(adjList, n, m);
    return 0;
}