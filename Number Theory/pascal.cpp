#include "bits/stdc++.h"
using namespace std;
#define int long long int 
#define endl "\n"

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif


const int N = 101;

vector <vector <int>> ncr(N, vector <int> (N));
void init(){
    ncr[0][0] = 1;
 
    for(int n=1;n<N;++n)  {
 
        ncr[n][0] = 1;
        for(int r=1;r<n;++r)  
          ncr[n][r] = ncr[n-1][r] + ncr[n-1][r-1];
        ncr[n][n] = 1;
 
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    init();
    
    cout << ncr[5][2];

    return 0;
}