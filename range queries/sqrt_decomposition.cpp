// https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int m = sqrtl(n) + 1;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i / m] += a[i];
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, val;
            cin >> x >> val;
            x--;
            b[x / m] += val - a[x];
            a[x] = val;
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int sum = 0;
            for (int i = l; i <= r;) {
                if (i % m == 0 && i + m - 1 <= r) {
                    sum += b[i / m];
                    i += m;
                } else {
                    sum += a[i];
                    i++;
                }
            }
            cout << sum << '\n';
        }
    }

    return 0;
}