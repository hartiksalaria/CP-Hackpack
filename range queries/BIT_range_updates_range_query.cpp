// https://www.codechef.com/problems/SPREAD
#include "bits/stdc++.h"
using namespace std;
#define int long long int 
#define endl "\n"

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif

struct BIT {
    int n;
    vector<int> fen1, fen2;
    BIT(int n) {
        this->n = n + 1;
        fen1.assign(n + 1, 0);
        fen2.assign(n + 1, 0);
    }  
    void add(vector<int> &b, int x, int val) {
        x++;
        while (x < n) {
            b[x] += val;
            x += x & -x;
        }
    }
    void update(int l, int r, int x) {
        add(fen1, l, x);
        add(fen1, r + 1, -x);
        add(fen2, l, x * (l - 1));
        add(fen2, r + 1, -x * r);
    }
    int sum(vector<int> &b, int x) {
        int res = 0;
        x++;
        while (x > 0) {
            res += b[x];
            x -= x & -x;
        }
        return res;
    }
    
    int prefix_sum(int x) {
        return sum(fen1, x) * x - sum(fen2, x);
    }
    
    int query(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
    void build(vector<int> &v) {
        for (int i = 0; i < n; ++i)
            update(i, i, v[i]);
    }
};


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> v(n, c);
    
    BIT tree(n);
    tree.build(v);
    
    
    while(m--){
        char ch;
        cin >> ch;
        if(ch == 'Q'){
            int x;
            cin >> x;
            x--;
            cout << tree.query(x, x) << endl; 
        }
        else {
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            tree.update(l, r, val);
        }
    }

    return 0;
}