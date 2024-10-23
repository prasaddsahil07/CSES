#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> adj(n, vector<ll>(n, LLONG_MAX));
    while(m--){
        ll u,v,d;
        cin>>u>>v>>d;
        u--;
        v--;
        adj[u][v] = min(adj[u][v], d);
        adj[v][u] = min(adj[v][u], d);
    }
    for(int via=0; via<n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)  adj[i][j] = 0;
                else if(adj[i][via] < LLONG_MAX && adj[via][j] < LLONG_MAX)
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(adj[a-1][b-1] != LLONG_MAX)    cout<<adj[a-1][b-1]<<endl;
        else    cout<<-1<<endl;
    }
}