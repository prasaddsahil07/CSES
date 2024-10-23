#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll, pair<ll, ll>>> edges;    
    while(m--){
        int u,v,x;
        cin>>u>>v>>x;
        u--;
        v--;
        edges.push_back({x, {v, x}});
    }
    vector<ll> points(n, LLONG_MAX);
    points[0]=0;
    for(int i=0; i<n-1; i++){
        for(auto e: edges){
            ll u=e.first;
            ll v=e.second.first;
            ll x=e.second.second;
            if(points[u] != LLONG_MAX && points[u] + x < points[v]){
                points[v] = points[u] + x;
            }
        }
    }
    for(auto e: edges){
        ll u=e.first;
        ll v=e.second.first;
        ll x=e.second.second;
        if(points[u] != LLONG_MAX && points[u] + x < points[v]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<points[n-1]<<endl;
}