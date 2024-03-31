#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(26, 0);
    for (int i = 0; i < n; i++) {
        v[s[i] - 'A']++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2) {
            cnt++;
        }
    }
    if (cnt > 1) {
        cout << "NO SOLUTION" << endl;
    } else {
        int l = 0, r = n - 1;
        string res(n, ' '); 
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2) {
                int mid = r - (r - l) / 2;
                res[mid] = i + 'A';
                v[i]--;
            }
            while (v[i] > 0) {
                res[l] = i + 'A';
                res[r] = i + 'A';
                l++;
                r--;
                v[i] -= 2;
            }
        }
        cout << res << endl;
    }
    return 0;
}
