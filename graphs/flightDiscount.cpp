#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<pair<ll, ll>>> g(n);
    for(ll i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        u--; 
        v--;
        g[u].push_back({v, w});
    }
    vector<ll> full(n, LLONG_MAX);
    vector<ll> disc(n, LLONG_MAX);
    full[0]=0;
    disc[0]=0;
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push({0, {0, 0}});
    while(!pq.empty()){
        ll c=pq.top().first;
        ll d=pq.top().second.first;
        ll f=pq.top().second.second;
        pq.pop();

        if(f == 1){
            if(disc[d] < c) continue;
        }
        if(f == 0){
            if(full[d] < c) continue;
        }

        for(auto e: g[d]){
            ll v=e.first;
            ll w=e.second;
            if(f == 0){
                if(full[v] > c+w){
                    full[v]=c+w;
                    pq.push({full[v], {v, 0}});
                }
                if(disc[v] > c+w/2){
                    disc[v]=c+w/2;
                    pq.push({disc[v], {v, 1}});
                }
            }
            if(f == 1){
                if(disc[v] > c+w){
                    disc[v]=c+w;
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }
    cout<<min(full[n-1], disc[n-1])<<endl;
}