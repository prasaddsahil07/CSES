#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef tuple<ll, ll, ll> edge;

void dijkstra(vector<vector<pair<ll, ll>>>& adjList, ll n, ll m, ll k){
    // vector<priority_queue<ll>> distGrid(n+1);
    // since we are using dijkstra algorithm so that means we are getting the distances in increasing order only at each node so rather than having a maxHeap of size n*k , we can have a 2-D vector only of size n*k;

    vector<vector<ll>> distGrid(n+1);

    // vector<int> visitCnt(n+1, 0);
    // visitCnt[1] = 1; // start from node 1
    // if we are using 2-D vector instead of vector of maxHeap then we don't need visitCnt

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1}); // start from node 1 with distance 0
    // distGrid[1].push(0);

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll u = it.second;

        // if(distGrid[u].size() > k)    continue; // skip if we have already visited k times
        // if(visitCnt[u] > k) continue; // skip if we have already visited k times
        // visitCnt[u]++;

        ll dist_u = it.first;

        if(distGrid[u].size() >= k) continue;
        distGrid[u].push_back(dist_u);

        for(auto e: adjList[u]){
            ll v = e.first;
            ll w = e.second;
            // distGrid[v].push(dist_u+w);
            // pq.push({dist_u+w, v});
            // if(distGrid[v].size() > k) {
            //     distGrid[v].pop(); // keep only the k smallest distances
            //     break; // break to avoid unnecessary processing
            // }
            

            // ll newDist = dist_u+w;
            // if(distGrid[v].size() < k || newDist < distGrid[v].top()){
            //     if(distGrid[v].size() == k) 
            //         distGrid[v].pop(); // remove the largest distance if we already have k distances
                
            //     distGrid[v].push(newDist);
            //     pq.push({newDist, v});
            // }

            ll newDist = dist_u+w;
            // distGrid[v].push_back(newDist);  // no need since we are already checking for node u
            pq.push({newDist, v});
        }
    }

    // vector<ll> ans;
    // while(!distGrid[n].empty()){
    //     ans.push_back(distGrid[n].top());
    //     distGrid[n].pop();
    // }
    // reverse(ans.begin(), ans.end());
    // for(auto a: ans)    cout<<a<<" ";

    for(int i=0; i<k; i++){
        cout<<distGrid[n][i]<<" ";
    }
    cout<<endl;
}

int main(){
    ll n, m, k;
    cin>>n>>m>>k;
    vector<vector<pair<ll, ll>>> adjList(n+1);
    for(int i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back({v, w});
    }
    dijkstra(adjList, n, m, k);
    return 0;
}