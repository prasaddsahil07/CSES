#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 100000007
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>


void dfs(int u, map<int, vector<int>>& adjList, vector<int>& subs){
    int sum = 0;
    
    for(auto v: adjList[u]){
        dfs(v, adjList, subs);
        sum += (1 + subs[v]);
    }

    subs[u] = sum;
}


int main(){
    int n;
    cin>>n;
    map<int, vector<int>> adjList;
    for(int i=2; i<n+1; i++){
        int p;
        cin>>p;
        adjList[p].pb(i);
    }

    vector<int> subOrdinates(n+1, -1);
    
    dfs(1, adjList, subOrdinates);

    for(int i=1; i<n+1; i++){
        cout<<subOrdinates[i]<<" ";
    }

    return 0;
}