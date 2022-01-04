#include <bits/stdc++.h>
using namespace std;


vector <int> a, b, c;

int N = 1e5+5;
vector <vector <int>> dp(N, vector <int> (3, -1));


int vacation_rec(int n, int d) {

    if(n==0)  {
        vector <int> v = {a[0], b[0], c[0]};
        return v[d];
    }

    if(dp[n][d] != -1)
      return dp[n][d];

    int ans = INT_MAX;
    if(d==0)
      ans = a[n] + max(vacation_rec(n-1, 1), vacation_rec(n-1, 2));
    else if(d==1)
      ans = b[n] + max(vacation_rec(n-1, 2), vacation_rec(n-1, 0));
    else 
      ans = c[n] + max(vacation_rec(n-1, 1), vacation_rec(n-1, 0));
    return dp[n][d] = ans;
}


int vacation_tab(int n)  {

  vector <vector <int>> dp(n, vector <int> (3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];


    for(int i=1;i<n;++i)  {

        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][1], dp[i-1][0]);

    }

   return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

}


int main()  {

    int n;
    cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i=0;i<n;++i)
      cin >> a[i] >> b[i] >> c[i];
    
    cout << max({vacation_rec(n-1, 1), vacation_rec(n-1, 0), vacation_rec(n-1, 2)});

    return 0;

}