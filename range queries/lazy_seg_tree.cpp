#include <bits/stdc++.h>
using namespace std;

struct seg {

    vector <int> st, lazy;
    int n;

    void init(int n)    {
        this->n = n;
        st.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    void build(int start, int end, int node, vector <int> &v)   {

        if(start == end)    {
            st[node] = v[start];
            return;
        }

        int mid = (start+end)/2;

        build(start, mid, node*2+1, v);
        build(mid+1, end, node*2+2, v);

        st[node] = st[node*2+1] + st[node*2+2];

    }

    void build(vector <int> &v) {
        build(0, n-1, 0, v);
    }


    int query(int start, int end, int l, int r, int node)   {

        
        if(lazy[node]){
            st[node] += (end - start + 1) * lazy[node];
            if(start != end){
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if(l > end or r < start)    {
            return 0;
        }

        if(l <= start and r >= end) {
            return st[node];
        }

        int mid = (start+end)/2;

        int q1 = query(start, mid, l, r, node*2+1);
        int q2 = query(mid+1, end, l, r, node*2+2);

        return q1+q2;

    }

    int query(int l, int r) {
        return query(0, n-1, l, r, 0);
    }

    void update(int start, int end, int node, int l, int r, int val)   {

            

        if (lazy[node] != 0) {
            st[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        
        if (start > r || end < l) {
            return ;
        }
        if (start >= l && end <= r) {
            st[node] += val * (end - start + 1);
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, 2 * node + 1, l, r, val);
        update(mid + 1, end, 2 * node + 2, l, r, val);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    void update(int l, int r, int x) {
        update(0, n-1, 0, l, r, x);
    }
};


int main()  {

    vector <int> v = {1, 2, 3, 4, 5, 6};
    int n = 6;
    seg s;
    s.init(n);
    s.build(v);


    cout << s.query(4, 5) << endl;
    s.update(0, 4, 8);
    cout << s.query(4, 5) << endl;;


    return 0;

}