#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;
    SegTree(int n): n(n), tree(4*n, 0) {}
    void update(int idx, int val, int node, int l, int r) {
        if(l == r) { tree[node] = max(tree[node], val); return; }
        int mid = (l + r) / 2;
        if(idx <= mid) update(idx, val, 2*node, l, mid);
        else update(idx, val, 2*node+1, mid+1, r);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
    int query(int L, int R, int node, int l, int r) {
        if(L > r || R < l) return 0;
        if(L <= l && r <= R) return tree[node];
        int mid = (l + r) / 2;
        return max(query(L, R, 2*node, l, mid),
                   query(L, R, 2*node+1, mid+1, r));
    }
    void update(int idx, int val) { update(idx, val, 1, 0, n-1); }
    int query(int L, int R) { return query(L, R, 1, 0, n-1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> L(n, -1), R(n, n);

    // nearest taller/equal to left
    {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[st.top()] < h[i]) st.pop();
            if(!st.empty()) L[i] = st.top();
            st.push(i);
        }
    }
    // nearest taller/equal to right
    {
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && h[st.top()] < h[i]) st.pop();
            if(!st.empty()) R[i] = st.top();
            st.push(i);
        }
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
        return h[a] > h[b];
    });

    SegTree seg(n);
    vector<int> dp(n, 1);
    int ans = 1;

    for(int i : idx) {
        int leftRange = (L[i] == -1) ? 0 : L[i] + 1;
        int rightRange = (R[i] == n) ? n-1 : R[i] - 1;

        int bestLeft = seg.query(leftRange, i-1);
        int bestRight = seg.query(i+1, rightRange);

        dp[i] = 1 + max(bestLeft, bestRight);
        seg.update(i, dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}
