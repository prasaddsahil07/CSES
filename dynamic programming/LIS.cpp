#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// int main(){
//     int n;
//     cin>>n;
//     vector<ll> vec(n);
//     for(auto& v:vec)    cin>>v;
//     vector<ll> dp(n, 1);
//     for(int i=1; i<n; i++){
//         for(int j=0; j<i; j++){
//             if(vec[j] < vec[i]){
//                 dp[i] = max(dp[i], 1+dp[j]);
//             }
//         }
//     }
//     ll maxi = *max_element(dp.begin(), dp.end());
//     cout<<maxi<<endl;
// }




// lazy sorting (nlogn -> LIS)

int main() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (auto &v : vec) cin >> v;
    vector<ll> tails;
    for(ll x : vec){
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if(it == tails.end()){
            tails.push_back(x);
        }
        else{
            *it = x;
        }
    }
    cout << tails.size() << endl;
}
