#include<bits/stdc++.h>
using namespace std;

bool isPossible = false;
stack<int> cyclePath;

bool DFS(map<int, vector<int>>& adj, vector<bool>& vis, vector<int>& parent, int u){
    vis[u] = true;
    for(auto& v: adj[u]){
        if(!vis[v]){
            parent[v] = u;
            if(DFS(adj, vis, parent, v)){
                return true;
            }
        }
        else if(parent[u] != v){  // Cycle detected
            isPossible = true;
            cyclePath.push(v);
            int curr = u;
            while(curr != v){
                cyclePath.push(curr);
                curr = parent[curr];
            }
            cyclePath.push(v);  // to complete the cycle
            return true;
        }
    }
    return false;
}

void roundTrip(map<int, vector<int>>& adj, int n, int m){
    vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(DFS(adj, vis, parent, i)){
                break;  // Stop after finding the first cycle
            }
        }
    }
    if(isPossible){
        cout << cyclePath.size() << endl;
        while(!cyclePath.empty()){
            cout << cyclePath.top() << " ";
            cyclePath.pop();
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    roundTrip(adj, n, m);
}
