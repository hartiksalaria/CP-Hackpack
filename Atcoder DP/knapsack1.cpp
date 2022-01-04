#include <bits/stdc++.h>
using namespace std;
#define int long long int

int N = 1e5+5;

vector <vector <int>> dp(105, vector <int> (N, -1));
int knapsack1_rec(vector <int> &val, vector <int> &wt, int n, int w)  {

      if(n==0 or w==0)
        return 0;

      if(dp[n][w] != -1)
        return dp[n][w];

      if(w >= wt[n-1])
        return dp[n][w] = max(knapsack1_rec(val, wt, n-1, w), knapsack1_rec(val, wt, n-1, w-wt[n-1])+val[n-1]);
      return dp[n][w] = knapsack1_rec(val, wt, n-1, w);

}


int knapsack1_tab(vector <int> &val, vector <int> &wt, int n, int w)  {

    vector <vector<int>> dp(n+1, vector <int> (w+1));
    for(int i=0;i<=n;++i)  {

        for(int j=0;j<=w;++j) {

              if(i==0 or j==0)
                dp[i][j] = 0;
              else if(wt[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
              else
                dp[i][j] = dp[i-1][j];

        }

    }

    return dp[n][w];

}



int32_t main()  {

    int n, w;
    cin >> n >> w;

    vector <int> wt(n), val(n);
    for(int i=0;i<n;++i)
      cin >> wt[i] >> val[i];


    cout << knapsack1_tab(val, wt, n, w) << endl;

    return 0;

}