#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main(){
    int n,x;
    cin>>n>>x;
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    vector<ll> vec(n);
    for(int i=0; i<n; i++)  {
        cin>>vec[i];
        dp[i][0]=1;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=x; j++){
            int skip = dp[i+1][j];
            int pick = 0;
            if(vec[i] <= j)
                pick = dp[i][j-vec[i]];
            dp[i][j] = (skip + pick)%MOD;
        }
    }
    cout<<dp[0][x]<<endl;
}