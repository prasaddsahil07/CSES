#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0));

    for (int k = 1; k <= m; k++) {
        if (vec[0] == 0 || vec[0] == k) {
            dp[1][k] = 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            if (vec[i - 1] == 0 || vec[i - 1] == k) {
                dp[i][k] = ((dp[i - 1][k - 1] + dp[i - 1][k]) % MOD + dp[i - 1][k + 1]) % MOD;
            } else {
                dp[i][k] = 0;
            }
        }
    }

    int ans = 0;
    for (int k = 1; k <= m; k++) {
        ans = (ans + dp[n][k]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
