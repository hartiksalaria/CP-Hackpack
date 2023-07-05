// https://www.spoj.com/problems/DQUERY/
// https://atcoder.jp/contests/abc293/tasks/abc293_g

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int N = 2e5 + 5;
const int sq = sqrtl(N);

int cnt[N];

struct Query {
    int l, r, id;
};

bool comp(const Query &a, const Query &b) {
    if (a.l / sq != b.l / sq) {
        return a.l < b.l;
    }
    if ((a.l / sq) & 1) {
        return a.r < b.r;
    }
    return a.r > b.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<Query> q(x);
    for (int i = 0; i < x; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].l--, q[i].r--;
        q[i].id = i;
    }

    sort(q.begin(), q.end(), comp);

    long long curr = 0;

    auto pr = [&](int t) -> long long {
        return 1LL * t * (t - 1) / 2;
    };

    int l = 0, r = 0;

    vector<long long> res(x);

    for (int i = 0; i < x; ++i) {
        while (r <= q[i].r) {
            curr += pr(cnt[a[r]]);
            cnt[a[r]]++;
            r++;
        }
        while (r - 1 > q[i].r) {
            r--;
            cnt[a[r]]--;
            curr -= pr(cnt[a[r]]);
        }
        while (l > q[i].l) {
            l--;
            curr += pr(cnt[a[l]]);
            cnt[a[l]]++;
        }
        while (l < q[i].l) {
            cnt[a[l]]--;
            curr -= pr(cnt[a[l]]);
            l++;
        }
        res[q[i].id] = curr;
    }

    for (int i = 0; i < x; ++i) {
        cout << res[i] << '\n';
    }

    return 0;
}