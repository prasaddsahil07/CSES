#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n,x;
    cin>>n>>x;
    vector<ll> dp(x+1, 1e9);
    vector<ll> vec(n);
    for(int i=0; i<n; i++)  cin>>vec[i];
    dp[0]=0;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(vec[j] <= i)
                dp[i] = min(dp[i], dp[i-vec[j]]+1);
        }
    }
    cout<<((dp[x] < 1e9)? dp[x]: -1)<<endl;
}