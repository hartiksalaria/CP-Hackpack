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
    vector<int> fen;
    BIT(int n) {
        this->n = n + 1;
        fen.assign(n + 1, 0);
    }  
    void add(int x, int val) {
        x++;
        while (x < n) {
            fen[x] += val;
            x += x & -x;
        }
    }
    void update(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
    int query(int x){
        int res = 0;
        x++;
        while (x > 0) {
            res += fen[x];
            x -= x & -x;
        }
        return res;
    }
    void build(vector<int> &v) {
        for (int i = 0; i < v.size(); ++i)
            update(i, i, v[i]);
    }
};


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> v = {1, 2, 3, 4, 5};
    BIT tree(5);
    tree.build(v);
    
    tree.update(0, 2, -4);
    tree.update(1, 3, 5);
    
    cout << tree.query(2) << endl;

    return 0;
}
