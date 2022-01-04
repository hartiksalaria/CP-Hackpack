#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define endl "\n"

const int N = 1e6+1;

vector <bool> tmp(N, 1);
vector <int> prime;

void sieve()  {
    tmp[0] = tmp[1] = 0;
    for(int i=2;i*i<N;++i)  {
          if(tmp[i])  {
              for(int j=i*i;j<N;j+=i) 
                tmp[j] = 0;
          }
    }

    for(int i=2;i<N;++i)
      if(tmp[i])  {
        prime.push_back(i);
      }

}


int32_t main()  {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    sieve();

    while(t--)  {

        int n, m;
        cin >> m >> n;

        vector <int> v(n-m+1, 1);
        for(auto p: prime)  {

              if(p*p > n)
                break;

              int start = ((m+p-1)/p)*p;
              for(int i=start;i<=n;i+=p) {
                    if(i <= p) continue;
                    v[i-m] = 0;
              }

        }

        for(int i=0;i<n-m+1;++i)
          if(v[i] and i+m > 1)
            cout << i + m << endl;

    }     

    return 0;

}