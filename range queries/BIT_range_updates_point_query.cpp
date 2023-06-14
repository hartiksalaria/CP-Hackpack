// https://codeforces.com/contest/1208/problem/D

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
    int n;
    vector<long long> fen;
    fenwick(int n) {
        this->n = n + 1;
        fen.assign(n + 1, 0);
    }
    void add(int x, long long val) {
        x++;
        while (x < n) {
            fen[x] += val;
            x += x & -x;
        }
    }
    void update(int l, int r, long long val) {
        add(l, val);
        add(r + 1, -val);
    }
    long long query(int x) {
        long long res = 0;
        x++;
        while (x > 0) {
            res += fen[x];
            x -= x & -x;
        }
        return res;
    }
    void build(vector<long long> &v) {
        for (int i = 0; i < v.size(); ++i) {
            update(i, i, v[i]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n), pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            pre[i] += pre[i - 1];
        }
        pre[i] += i;
    }
    fenwick ds(n);
    ds.build(pre);
    vector<int> res(n);
    for (int i = n - 1; i >= 0; --i) {
        int low = 0, high = n - 1;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ds.query(mid) <= a[i]) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        res[i] = ans + 1;
        ds.update(res[i], n, -res[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " \n"[i == n - 1];
    }
    return 0;
}