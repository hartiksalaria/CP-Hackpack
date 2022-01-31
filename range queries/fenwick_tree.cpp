#include "bits/stdc++.h"
using namespace std;

struct fenwick {
    int n;
    vector <int> fn;
    void init(int n){
        this->n = n+1;
        fn.resize(this->n, 0);
    }
    
    void add(int x, int y){
        x++;
        while(x < n){
            fn[x] += y;
            x += (x & (-x));
        }
    }
    
    void build(vector <int> v){
        for(int i=0;i<v.size();++i){
            add(i, v[i]);
        }
    }
    
    int sum(int x){
        x++;
        int ans=0;
        while(x){
            ans += fn[x];
            x -= (x & (-x));
        }
        return ans;
    }
    
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }
     
};

int main(){
    
    vector <int> v = {1, 2, 3, 4, 5, 6};
    fenwick tree;
    tree.init(v.size());
    tree.build(v);
    
    cout << tree.sum(0, 2);
    tree.add(0, -19);
    cout << "\n" << tree.sum(0, 2) << "\n";
    
    return 0;
}


