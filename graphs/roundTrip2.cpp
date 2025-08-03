#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll node = -1;  // global variable to store the node where cycle is found
 
bool dfs(vector<vector<int>>& adjList, ll u, vector<bool>& vis, vector<bool>& inRecursion, vector<ll>& parent){
    vis[u] = true;
    inRecursion[u] = true;
 
    for(auto v: adjList[u]){
 
        if(!vis[v]){
            parent[v] = u;
            if(dfs(adjList, v, vis, inRecursion, parent))   return true;
        }
 
        else if(inRecursion[v]){
            // if we reach a visited node which is not the parent of current node, then we have found a cycle
            parent[v] = u;  // update parent to construct the path later
            node = u;  // store the node where cycle is found
            return true;  // no need to continue DFS further
        }
    }
    
    inRecursion[u] = false; // backtrack, mark the node as unvisited for other paths
    return false;
}
 
void solve(vector<vector<int>>& adjList, ll n, ll m){
    vector<bool> vis(n+1, false);
    vector<bool> inRecursion(n+1, false);
    vector<ll> parent(n+1, -1);  // since we need to construct the path as well
 
    bool isCycle = false;
    for(int i=1; i<=n; i++){
        if(vis[i])  continue;
        if(dfs(adjList, i, vis, inRecursion, parent)){
            isCycle = true;
            break;
        }
    }
 
    if(!isCycle){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    // cout<<"POSSIBLE"<<endl;
 
    vector<ll> path;
    ll curr = node;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
        if(curr == node)    break;
    }
    path.push_back(node);  // add the node where cycle is found again to complete the cycle
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    for(ll p: path){
        cout<<p<<" ";
    }
    cout<<endl;
}
 
 
int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<int>> adjList(n+1);
    for(int i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;
        adjList[u].push_back(v);    // directed graph
    }
    solve(adjList, n, m);
    return 0;
 
}
