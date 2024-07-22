#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> price(n);
    for(int i=0; i<n; i++)  cin>>price[i];
    vector<int> pages(n);
    for(int i=0; i<n; i++)  cin>>pages[i];
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            int pri = price[i-1];
            int pag = pages[i-1];
            int pick = j>=pri ? dp[i-1][j-pri] + pag: 0;
            int skip = dp[i-1][j];
            dp[i][j] = max(pick, skip);
        }
    }
    cout<<dp[n][x]<<endl;
}