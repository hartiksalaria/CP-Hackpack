// https://codeforces.com/contest/1332/problem/C

#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
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
        parent[s2] = s1;
        rank[s1] += rank[s2];
    }
    int sz(int a) {
        return rank[get(a)];
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        DSU t(n);
        for (int i = 0; i < k; ++i)
            for (int j = i + k; j < n; j += k) 
               t.merge(i, j);
        for (int i = 0; i < n / 2; ++i) 
            t.merge(i, n - 1 - i);
        map<int, map<char, int>> f;
        for (int i = 0; i < n; ++i) 
            f[t.get(i)][s[i]]++;
        int ans = 0;
        for (auto &[x, _f]: f) {
            int sz = t.sz(x);
            int mx = 0;
            for (auto [_, __f]: _f)
                mx = max(mx, __f);
            ans += sz - mx;
        }
        cout << ans << endl;
    }

    return 0;
}