#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> topologicalSort(vector<vector<ll>>& adjList, vector<ll>& inDegree, ll n){
    queue<ll> q;
    for(ll u=1; u<=n; u++){
        if(!inDegree[u]){
            q.push(u);
        }
    }

    vector<ll> ans;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v: adjList[u]){
            inDegree[v]--;
            if(!inDegree[v]){
                q.push(v);
            }
        }
    }

    return ans;
}

void bfs(vector<vector<ll>>& adjList, ll n){
    vector<ll> pathLen(n+1, 0);
    vector<ll> parent(n+1, -1);
    vector<ll> topoArr;
    vector<ll> inDegree(n+1, 0);

    for(ll u=1; u<=n; u++){
        for(auto v: adjList[u]){
            inDegree[v]++;
        }
    }

    topoArr = topologicalSort(adjList, inDegree, n);

    pathLen[1] = 1;  // starting from node 1
    for(auto u: topoArr){
        if(pathLen[u] == 0) continue;  // if this node is not reachable, skip it
        for(auto v: adjList[u]){
            if(pathLen[v] < pathLen[u]+1){
                pathLen[v] = pathLen[u]+1;
                parent[v] = u;  // store the parent to reconstruct the path later
            }
        }
    }

    if(pathLen[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    // cout<<pathLen[n]+1<<endl;
    vector<ll> path;
    path.push_back(n);
    ll i=n;
    while(parent[i] != -1){
        path.push_back(parent[i]);
        i = parent[i];
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    for(auto p: path)   cout<<p<<" ";
    cout<<endl;
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adjList(n+1);
    for(int i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;
        adjList[u].push_back(v);    // directed graph
    }
    bfs(adjList, n);
    return 0;
}