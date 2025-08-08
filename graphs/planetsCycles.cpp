#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dist;
vector<ll> ans;
vector<bool> vis;

ll cycleStart = -1;
ll cycleLen = 0;

void dfs(ll u, vector<ll>& a, ll currDist){
    // if(vis[u])  return; // If already visited, return
    vis[u] = true;
    dist[u] = currDist;     // Store the distance from the start of the DFS

    ll v = a[u];
    if(vis[v] == false){  // If v is not visited
        dfs(v, a, currDist+1);
    }
    else{
        if(ans[v] == 0){                      // If not already processed
            cycleStart = v;
            cycleLen = currDist-dist[v]+1;    // Length of the cycle, currDist = dist[u]
        }
        else{
            cycleLen = ans[v];               // If already processed, just set cycleStart
        }
    }

    if(cycleStart != -1){
        // if we are in or after a cycle start
        ans[u] = cycleLen;  // Set the answer for this node

        // if we are at the cycle start
        if(u == cycleStart){
            cycleStart = -1;  // Reset cycle start after processing
        }
    }
    else{
        ans[u] = ans[v]+1;  // If not in a cycle, set the answer based on the next node
    }
}

int main(){
    ll n;
    cin>>n;

    dist.resize(n+1, LLONG_MAX);
    ans.resize(n+1, 0);
    vis.resize(n+1, false);

    vector<ll> a(n+1, 0);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(ll u=1; u<=n; u++){
        if(vis[u])    continue;  // Skip if already processed
        dfs(u, a, 0);
    }

    for(ll u=1; u<=n; u++){
        cout<<ans[u]<<" ";
    }

    return 0;
}