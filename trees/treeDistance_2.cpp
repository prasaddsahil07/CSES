#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 100000007
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>


ll subTreeSize[200001];
ll ans[200001];
int N;


void dfs(int u, int p, ll depth, map<int, vector<int>>& adjList){
    ans[1] += depth;            // mark the current depth of the node part of the answer
    subTreeSize[u] = 1;         // initialize with the node itself
    for(auto v: adjList[u]){
        if(v == p)  continue;
        dfs(v, u, depth+1, adjList);
        subTreeSize[u] += subTreeSize[v];   // subtree size of parent is added with the same of the child
    }
}


void re_root(int u, int p, map<int, vector<int>>& adjList){
    for(auto v: adjList[u]){
        if(v == p)  continue;
        ans[v] = ans[u]+N-2*subTreeSize[v];     // derived formula
        re_root(v, u, adjList);
    }
}


int main(){
    int n;
    cin>>n;
    N=n;
    map<int, vector<int>> adjList;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);   // tree in the form of undirected graph
    }

    // dfs to get the ans for node 1 that is the root
    dfs(1, -1, 0, adjList);

    // re root the tree with the help of derived formula
    re_root(1, -1, adjList);

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}