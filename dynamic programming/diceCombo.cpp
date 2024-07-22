#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n){
    vector<ll> dp(n+1, 0);
    dp[0]=1;
    ll mod=1e9+7;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=6 && j<=i; j++){
            dp[i]=(dp[i]+(dp[i-j]))%mod;
        }
    }
    return dp[n];
}

int main(){
    ll n;
    cin>>n;
    cout<< solve(n) <<endl;
}