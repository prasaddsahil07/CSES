#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 100000007
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>


int dist[200001];
int preservedDist[200001];


void dfs(int u, int p, map<int, vector<int>>& adjList){
    for(auto v: adjList[u]){
        if(v == p)  continue;
        dist[v] = dist[u]+1;
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

    int maxDistNode = -1;  // node with max dist from arbitrary root(1)
    int maxDist = -1;     // max dist from arbitrary root(1)

    dfs(1, -1, adjList);        // dfs from root 1 (get the maxdistNode -> one end of the diameter for sure)


    for(int i=1; i<n+1; i++){
        if(dist[i] > maxDist){
            maxDist = dist[i];    // finding the max dist node from root 1
            maxDistNode = i;
        }
        dist[i] = 0;       // resetting dist array for next dfs
    }

    dfs(maxDistNode, -1, adjList);     // start dfs from that one end of the diameter to get the actual diameter


    int maxDistNode2 = -1;          // the other end of the diameter
    maxDist = -1;           
    for(int i=1; i<n+1; i++){
        if(dist[i] > maxDist){
            maxDistNode2 = i;
            maxDist = dist[i];    // finding the max dist from maxdistNode which is the diameter of the tree
        }
        preservedDist[i] = dist[i];
        dist[i] = 0;        // resetting the dist for fair calculation
    }


    dfs(maxDistNode2, -1, adjList);   // final DFS to ensure we get the max dist from both sides of the diameter, now the dephth array contains the distance of the farthest node for each node

    for(int i=1; i<n+1; i++){
        cout<<max(dist[i], preservedDist[i])<<" ";
    }

    return 0;
}