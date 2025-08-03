#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

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
    vector<ll> numWays(n+1, 0);
    // vector<ll> parent(n+1, -1);
    vector<ll> topoArr;
    vector<ll> inDegree(n+1, 0);

    for(ll u=1; u<=n; u++){
        for(auto v: adjList[u]){
            inDegree[v]++;
        }
    }

    topoArr = topologicalSort(adjList, inDegree, n);

    numWays[1] = 1;  // starting from node 1
    for(auto u: topoArr){
        if(numWays[u] == 0) continue;  // if this node is not reachable, skip it
        for(auto v: adjList[u]){
            numWays[v] = (numWays[v] + numWays[u]) % MOD;  // accumulate the number of ways to reach node v
            // parent[v] = u;  // store the parent to reconstruct the path later
        }
    }

    // if(numWays[n] == 0){
    //     cout<<"IMPOSSIBLE"<<endl;
    //     return;
    // }

    cout<<(numWays[n] % MOD)<<endl;
    // vector<ll> path;
    // path.push_back(n);
    // ll i=n;
    // while(parent[i] != -1){
    //     path.push_back(parent[i]);
    //     i = parent[i];
    // }
    // reverse(path.begin(), path.end());
    // cout<<path.size()<<endl;
    // for(auto p: path)   cout<<p<<" ";
    // cout<<endl;
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