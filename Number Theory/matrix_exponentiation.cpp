#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

const int mod = 1e9 + 7;

struct Mat {
    vector<vector<int>> m;
    Mat() {
        m.assign(2, vector<int> (2, 0));
    }
    void identity() {
        for (int i = 0; i < 2; ++i) {
            m[i][i] = 1;
        }
    }
    Mat operator *(Mat a) {
        Mat res;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
    void set() {
        m[0][0] = m[0][1] = m[1][0] = 1;
    }
};

int fib(int n) {
    if (n <= 2)
        return 1;
    n -= 2;
    Mat res, T;
    res.identity();
    T.set();
    while (n) {
        if (n & 1)
            res = res * T;
        T = T * T;
        n >>= 1;
    }
    return (res.m[0][0] + res.m[0][1]) % mod;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cout << fib(53);

    return 0;
}