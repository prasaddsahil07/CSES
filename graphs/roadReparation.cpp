#include <bits/stdc++.h>
using namespace std;
#define ll long long

void primsAlgo(vector<vector<pair<ll, ll>>>& adjList, ll n, ll m){
    vector<bool> vis(n+1, false);

    ll nodeCntInMST = 0; // Count of nodes in the Minimum Spanning Tree (MST) to check if all nodes are included

    ll sum = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, 1}); // {cost, node}

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        ll u = it.second; // current node
        ll cost_u = it.first; // cost to reach this node

        if(vis[u])  continue;   // If already visited, skip the costlier path(because of minHeap)

        vis[u] = true;
        sum += cost_u;  // Add the cost of the current node to the total sum
        nodeCntInMST++; // Increment the count of nodes in the MST

        for(auto nbr: adjList[u]){
            ll v = nbr.first;
            ll cost_v = nbr.second;

            // if(!vis[v]){
            pq.push({cost_v, v});   // Push the adjacent node with its cost (not the cumulative cost)
            // }
        }
    }

    if(nodeCntInMST != n){
        cout<<"IMPOSSIBLE"<<endl; // If not all nodes are included in the MST, print "IMPOSSIBLE"
        return;
    }

    cout<<sum<<endl;  // Output the total cost of the minimum spanning tree
}

int main(){
    ll n, m;
    cin>>n>>m;

    vector<vector<pair<ll, ll>>> adjList(n+1);

    for(int i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // undirected graph
    }

    primsAlgo(adjList, n, m);
    return 0;
}