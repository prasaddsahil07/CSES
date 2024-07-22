#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main(){
    int n,x;
    cin>>n>>x;
    vector<ll> dp(x+1,0);
    vector<ll> vec(n);
    for(int i=0; i<n; i++)  cin>>vec[i];
    dp[0]=1;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(vec[j] <= i)
                dp[i] = (dp[i] + dp[i-vec[j]])%MOD;
        }
    }
    cout<<dp[x]<<endl;
}