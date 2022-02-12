#include "bits/stdc++.h"
using namespace std;
#define int long long int 
#define endl "\n"

vector <int> fact(1001);
const int m = 1e9+7;

void presolve(){
    fact[0] = 1;
    for (int i = 1; i <= 1000; i++)
        fact[i] = (fact[i - 1] * i) % m;
}

int expo(int x, int y, int m){
    int res = 1; 
 
    x = x % m; 

    while (y > 0){
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1; 
        x = (x * x) % m;
    }
    return res;
}
 
int modInverse(int n,int m){
    return expo(n, m - 2, m);
}
 
int ncr(int n, int r){

    if (n < r)
        return 0;
    if (r == 0)
        return 1;
 
    return (fact[n] * modInverse(fact[r], m) % m * modInverse(fact[n - r], m) % m) % m;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    presolve();


    return 0;
}