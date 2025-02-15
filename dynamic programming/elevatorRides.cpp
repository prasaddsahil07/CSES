#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> weights(n);
    for (auto& w : weights) cin >> w;
    
    // DP array to store (min subsets required, last subset's weight) for each mask
    vector<pair<int, ll>> dp(1 << n, {n+1, 0});
    dp[0] = {1, 0}; // base case: no items taken, one empty subset with weight 0
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {  // if i-th item is in the current subset
                int prev_mask = mask ^ (1 << i);  // subset without i-th item
                auto& subsets = dp[prev_mask].first;
                auto& lastWeight= dp[prev_mask].second;

                // Check if we can add this item to the last subset
                if (lastWeight + weights[i] <= x) {
                    dp[mask] = min(dp[mask], {subsets, lastWeight + weights[i]});
                } 
                else {  // Otherwise, start a new subset for this item
                    dp[mask] = min(dp[mask], {subsets + 1, weights[i]});
                }
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;  // answer for the full set
    return 0;
}