// https://codeforces.com/contest/1332/problem/C
// https://codeforces.com/contest/1768/problem/D

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct DSU {
    int components;
    vector<int> parent, rank;
    DSU(int n) {
        #warning be careful with initializing components
        components = n;
        parent.assign(n, -1);
        rank.assign(n, 1);
    }
    int get(int a) {
        if (parent[a] == -1)
            return a;
        return parent[a] = get(parent[a]);
    }
    void merge(int a, int b) {
        int s1 = get(a);
        int s2 = get(b);
        if (s1 == s2)
            return;
        if (rank[s1] < rank[s2])
            swap(s1, s2);
        components--;
        parent[s2] = s1;
        rank[s1] += rank[s2];
    }
    int sz(int a) {
        return rank[get(a)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n), pos(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i]--;
            pos[p[i]] = i;
        }
        DSU s(n);
        for (int i = 0; i < n; ++i) {
            if (p[i] != i) {
                s.merge(p[i], pos[p[i]]);
            }
        }

        int inv = n - s.components;
        int ans = 1e9;
        for (int i = 1; i < n; ++i) {
            if (s.get(i) == s.get(i - 1)) {
                ans = min(ans, inv - 1);
            } else {
                ans = min(ans, inv + 1);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}