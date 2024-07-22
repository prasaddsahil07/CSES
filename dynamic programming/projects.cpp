#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

struct Project {
    ll start;
    ll end;
    ll reward;
};

bool compare(Project& p1, Project& p2) {
    return p1.end < p2.end;
}

int bin_search(ll val, int start, int end, vector<Project>& arr) {
    int ans = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid].end < val) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<Project> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].end >> arr[i].reward;
    }
    sort(arr.begin(), arr.end(), compare);
    vector<ll> dp(n);
    dp[0] = arr[0].reward; // base case
    for (int i = 1; i < n; i++) {
        ll opt1 = dp[i - 1];
        ll opt2 = arr[i].reward;
        int idx = bin_search(arr[i].start, 0, i - 1, arr);
        if (idx != -1) {
            opt2 += dp[idx];
        }
        dp[i] = max(opt1, opt2);
    }
    cout << dp[n - 1] << endl; // 0 based indexing
    return 0;
}
