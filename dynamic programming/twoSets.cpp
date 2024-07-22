#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

// Function to calculate modular inverse of a under modulo p
ll modInverse(ll a, ll p) {
    ll result = 1, exponent = p-2;
    while (exponent) {
        if (exponent % 2) result = (result * a) % p;
        a = (a * a) % p;
        exponent /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int totalSum = n * (n + 1) / 2;

    if (totalSum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = totalSum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }

    ll result = dp[n][target];
    result = (result * modInverse(2, MOD)) % MOD; // Since every pair is counted twice

    cout << result << endl;
    return 0;
}
