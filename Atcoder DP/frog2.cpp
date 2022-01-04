#include <bits/stdc++.h>
using namespace std;
#define int long long int
  
int N = 1e5+5;
vector <int> dp(N, -1);

int frog2_rec(vector <int> &v, int i, int k) {

    if(i == 0)
      return 0;

    if(dp[i] != -1)
      return dp[i];

    int ans = INT_MAX;
    for(int j=1;j<=k && i-j >= 0;++j) {
        ans = min(ans, abs(v[i] - v[i-j]) + frog2_rec(v, i-j, k));
    }

    return dp[i] = ans;

}




int frog2_tab(vector <int> v, int k)  {

    int n = (int)v.size();
    vector <int> dp(n, INT_MAX);
    dp[0] = 0;

    for(int i=1;i<n;++i)  {

        for(int j=1;j<=k;++j) {

            if(j > i) 
              break;
            dp[i] = min(dp[i], dp[i-j] + abs(v[i]-v[i-j]));

        }

    }

    return dp[n-1];

}


int32_t main()  {

    int n, k;
    cin >> n >> k;

    vector <int> v(n);
    for(int i=0;i<n;++i)
      cin >> v[i];

    cout << frog2_rec(v, n-1, k) << endl;

    return 0;

}