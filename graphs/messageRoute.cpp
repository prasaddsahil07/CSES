#include<bits/stdc++.h>
using namespace std;


void messageRoute(map<int, vector<int>>& adj, int n, int m){
    vector<bool> vis(n+1, false);
    bool isPossible = false;
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int& v:adj[u]){
            if(!vis[v]){
                vis[v] = true;
                parent[v] = u;
                q.push(v);
                if (v == n) {
                    vector<int> path;
                    for (int i = n; i != -1; i = parent[i]) {
                        path.push_back(i);
                    }
                    reverse(path.begin(), path.end());
                    cout << path.size() << endl;
                    for (int node : path) {
                        cout<<node<<" ";
                    }
                    cout<<endl;
                    return;
                }
            }
        }   
    }
    cout<<"IMPOSSIBLE"<<endl;
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
    messageRoute(adj, n, m);
}