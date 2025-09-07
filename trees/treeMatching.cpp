#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 100000007
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>


int dp[200001][2];          // dp[u][0] -> max matching in subtree rooted at u, u not matched
                            // dp[u][1] -> max matching in subtree rooted at u, u matched   


int solve(int u, int included, int p, map<int, vector<int>>& adjList){
    if(dp[u][included] != -1) return dp[u][included];

    if(included){
        int totalChildSum = 0;
        for(auto v: adjList[u]){
            if(v == p)  continue;
            totalChildSum += solve(v, 1, u, adjList); // if u is matched, children can be either matched or not matched but we take the matched scenario later on we will remove one of the child nodes
        }

        int ans = 0;
        for(auto v: adjList[u]){
            if(v == p)  continue;
            int val = 1+solve(v, 0, u, adjList)+(totalChildSum-dp[v][1]); // if we match u with v, v cannot be matched but all other children can be either matched or not matched
            ans = max(ans, val);
        }

        dp[u][included] = ans;
        return dp[u][included];
    }
    else{
        int childSum = 0;
        for(auto v: adjList[u]){
            if(v == p)  continue;
            childSum += solve(v, 1, u, adjList); // if u is not matched, all children must be matched(to    maximize matching)
        }

        dp[u][included] = childSum;
        return dp[u][included];
    }
}


int main(){
    int n;
    cin>>n;
    map<int, vector<int>> adjList;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);   // tree in the form of undirected graph
    }

    memset(dp, -1, sizeof(dp));

    cout << max(solve(1, 0, -1, adjList), solve(1, 1, -1, adjList)) << endl;    // root can be either matched or not matched

    return 0;
}