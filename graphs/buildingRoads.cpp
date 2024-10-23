#include<bits/stdc++.h>
using namespace std;

void DFS(map<int, vector<int>>& adj, vector<bool>& vis, int node){
    vis[node] = true;
    for(auto& ngbr:adj[node]){
        if(!vis[ngbr]){
            DFS(adj, vis, ngbr);
        }
    }
}

void buildingRoads(map<int, vector<int>>& adj, int n, int m){
    vector<bool> vis(n+1, false);
    vector<pair<int,int>> connection;
    int compCnt=0;
    for(int i=0; i<n; i++){
        if(!vis[i+1]){
            DFS(adj, vis, i+1);
            compCnt++;
            if(compCnt>1){
                connection.push_back({i,i+1});
            }
        }
    }
    cout<<compCnt-1<<endl;
    for(auto& conn:connection){
        cout<<conn.first<<" "<<conn.second<<endl;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    map<int, vector<int>> adj;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    buildingRoads(adj, n, m);
}