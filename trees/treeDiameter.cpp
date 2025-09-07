#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 100000007
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>


int depth[200001];

void dfs(int u, int p, map<int, vector<int>>& adjList){
    for(auto v: adjList[u]){
        if(v == p)  continue;
        depth[v] = depth[u]+1;
        dfs(v, u, adjList);
    }
}


int main(){
    int n;
    cin>>n;
    map<int, vector<int>> adjList;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);   // tree in the form of undirected graph
    }

    int maxDepthNode = -1;  // node with max depth from arbitrary root(1)
    int maxDepth = -1;     // max depth from arbitrary root(1)

    dfs(1, -1, adjList);        // dfs from root 1 (get the maxDepthNode -> one end of the diameter for sure)

    for(int i=1; i<n+1; i++){
        if(depth[i] > maxDepth){
            maxDepth = depth[i];    // finding the max depth node from root 1
            maxDepthNode = i;
        }
        depth[i] = 0;       // resetting depth array for next dfs
    }

    dfs(maxDepthNode, -1, adjList);     // start dfs from that one end of the diameter to get the actual diameter

    for(int i=1; i<n+1; i++){
        if(depth[i] > maxDepth){
            maxDepth = depth[i];    // finding the max depth from maxDepthNode which is the diameter of the tree
        }
    }

    cout<<maxDepth<<endl;

    return 0;
}