// https://codeforces.com/contest/1709/problem/D

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl "\n"

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

struct SparseTable {
    using T = int;
    int n;
    int h;
    vector<vector<T>> table;
 
    T op(T x, T y) {
        return max(x, y);
    }
    
    SparseTable(const vector<T> &v) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    // gives op in the range [a, b)
    T get(int l, int r) {
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    
    SparseTable table(a);
    
    int q;
    cin >> q;
    
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1--, x2--, y1--, y2--;
        if (abs(x1 - x2) % k || abs(y1 - y2) % k) {
            cout << "NO" << endl;
            continue;
        }
        
        
        if (y1 > y2)
            swap(y1, y2);
        
        int h = table.get(y1, y2 + 1);
        
        x1++;
        
        int t = (n - x1) / k;
        int up = x1 + t * k;
        
        // debug(mp(h, up));
        
        cout << (up > h ? "YES" : "NO") << endl;
        
    }

    return 0;
}