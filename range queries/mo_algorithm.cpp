// https://www.spoj.com/problems/DQUERY/
// https://atcoder.jp/contests/abc293/tasks/abc293_g

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct Query {
    int l, r, ans, id, block;
    bool operator<(Query Q) const {
        if (this->block == Q.block) {
            return this->r < Q.r;
        }
        return this->block < Q.block;
    }
};

const int nax = 1e6 + 5, N = 3e4 + 5, _Q = 2e5 + 5;
int cnt[nax], a[N];
Query Q[_Q];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = sqrtl(n);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--, Q[i].r--;
        Q[i].id = i;
        Q[i].block = Q[i].l / m;
    }

    sort(Q, Q + q);

    int dis = 0;
    int x = 0, y = 0;

    auto add = [&](int x) -> void {
        cnt[x]++;
        if (cnt[x] == 1) {
            dis++;
        }
    };

    auto remove = [&](int x) -> void {
        cnt[x]--;
        if (cnt[x] == 0) {
            dis--;
        }
    };

    for (int i = 0; i < q; ++i) {
        while (y <= Q[i].r) {
            add(a[y]);
            y++;
        }
        while (y > Q[i].r + 1) {
            y--;
            remove(a[y]);
        }
        while (x < Q[i].l) {
            remove(a[x]);
            x++;
        }
        while (x > Q[i].l) {
            x--;
            add(a[x]);
        }
        Q[i].ans = dis;
    }

    sort(Q, Q + q, [&](Query &a, Query &b) {
        return a.id < b.id;
    });

    for (int i = 0; i < q; ++i) {
        cout << Q[i].ans << '\n';
    }

    return 0;
}