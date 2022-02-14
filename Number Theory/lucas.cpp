#include "bits/stdc++.h"
using namespace std;
#define int long long int 
#define endl "\n"

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif

int p = 1e9+7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}
 
int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}
 
int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}
 
int po(int a, int deg){
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}
 
int inv(int n){
    return po(n, p-2);
}
 
 
const int N = 1200000;
 
vector<int> fact(N), invfacs(N);
 
void init(){
    fact[0] = 1;
    for (int i = 1; i<N; i++) fact[i] = mul(fact[i-1], i);
    invfacs[N-1] = inv(fact[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}
 
int ncr(int n, int k){
    if (n<k) return 0;
    if (n<0 or k<0) return 0;
    return mul(fact[n], mul(invfacs[k], invfacs[n-k]));
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    init();
    
    cout << ncr(5, 2) << endl;
    cout << fact[5];

    return 0;
}