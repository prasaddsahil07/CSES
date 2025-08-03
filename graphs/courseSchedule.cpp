#include <bits/stdc++.h>
using namespace std;
#define ll long long

// using kahn's algorithm for topological short
void courseSchedule(vector<vector<ll>>& adjList, ll n){
    // calculate the in degree for each of the nodes
    vector<ll> inDegree(n+1, 0);
    for(ll u=1; u<=n; u++){
        for(auto v: adjList[u]){
            inDegree[v]++;
        }
    }
    // for(int i=1; i<=n; i++)  cout<<inDegree[i]<<" ";
    // cout<<endl;

    vector<ll> ans;

    queue<ll> q;    // for BFS
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
            q.push(i);
            // ans.push_back(i);
        }
    }

    while(!q.empty()){
        ll u = q.front();
        if(inDegree[u] == 0)    ans.push_back(u);
        q.pop();
        for(auto v: adjList[u]){
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
                // ans.push_back(v);
            }
        }
    }

    if(ans.size() != n){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    for(auto a: ans)    cout<<a<<" ";
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
    courseSchedule(adjList, n);
    return 0;
}