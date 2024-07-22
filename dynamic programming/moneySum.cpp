#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;


int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    int maxSum = accumulate(vec.begin(), vec.end(), 0);

    vector<vector<bool>> dp(n+1, vector<bool>(maxSum+1, false));

    // base case
    dp[0][0] = true;
    // transition
    for(int i=1; i<=n; i++){
        for(int j=0; j<=maxSum; j++){
            dp[i][j] = dp[i-1][j];
            if(j>= vec[i-1] && dp[i-1][j-vec[i-1]]){
                dp[i][j] = true;
            }
        }
    }
    
    vector<int> ans;
    for(int j=1; j<=maxSum; j++){
        if(dp[n][j])
            ans.push_back(j);
    }
    // print answer
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}