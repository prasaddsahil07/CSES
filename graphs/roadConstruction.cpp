#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU{
    private:
        vector<ll> parent, size;
    public:
        DSU(ll n){
            parent.resize(n+1);
            size.resize(n+1, 1); // Initialize size of each component to 1
            iota(parent.begin(), parent.end(), 0); // Initialize parent to itself
        }

        ll find(ll u){
            if(parent[u] != u){
                parent[u] = find(parent[u]); // Path compression
            }
            return parent[u]; // Return the root of the component
        }

        ll uniteFn(ll u, ll v){
            ll par_u = find(u);
            ll par_v = find(v);

            // if(par_u == par_v) return ; // Already in the same set

            ll maximumSize = -1;

            if(size[par_u] > size[par_v]){
                parent[par_v] = par_u; // Attach smaller size tree under larger size tree
                size[par_u] += size[par_v]; // Increase the size of the new root
                maximumSize = max(maximumSize, size[par_u]);
            }
            else if(size[par_u] < size[par_v]){
                parent[par_u] = par_v; // Attach smaller size tree under larger size tree
                size[par_v] += size[par_u]; // Increase the size of the new root
                maximumSize = max(maximumSize, size[par_v]);
            }
            else{
                parent[par_v] = par_u; // Attach one to the other
                size[par_u] += size[par_v]; // Increase the size of the new root
                maximumSize = max(maximumSize, size[par_u]);
            }

            return maximumSize; // Return the size of the new component
        }
};

int main(){
    ll n,m ;
    cin>>n>>m;

    ll compCnt = n; // Count of connected components initially
    ll maxSize = 1; // Maximum size of any component initially

    DSU dsu(n);

    for(int i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;

        ll par_u = dsu.find(u);
        ll par_v = dsu.find(v);

        if(par_u == par_v){
            cout<<compCnt<<" "<<maxSize<<endl; // If they are already connected, print current component count and max size
        }
        else{
            maxSize = max(maxSize, dsu.uniteFn(u, v)); // Unite the components and update max size
            compCnt--; // Decrease the component count as two components are now united
            cout<<compCnt<<" "<<maxSize<<endl; // Print the updated component count and max size
        }
    }
    return 0;
}