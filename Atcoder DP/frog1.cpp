#include <bits/stdc++.h>
using namespace std;


int N = 1e5+5;
vector <int> dp(N, -1);

int frog1_rec(vector <int> &v, int i) {

    if(i < 0)
      return 1e4+1;
    if(i==0)
      return 0;

    if(dp[i] != -1)
      return dp[i];

    int ch1 = abs(v[i-1]-v[i]) + frog1_rec(v, i-1);
    int ch2 = abs(v[i-2]-v[i]) + frog1_rec(v, i-2);

    return dp[i] = min(ch1, ch2);

}



int frog1_tab(vector <int> &v)  {

    int n = (int)v.size();
    vector <int> dp(n);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);

    for(int i=2;i<n;++i)  {

          dp[i] = min(dp[i-1] + abs(v[i] - v[i-1]), dp[i-2] + abs(v[i] - v[i-2]));

    }

    return dp[n-1];

}


int main()  {

    int n;
    cin >> n;

    vector <int> v(n);
    for(int i=0;i<n;++i)
      cin >> v[i];

    cout << frog1_tab(v);


    return 0;

}