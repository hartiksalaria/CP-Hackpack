#include <bits/stdc++.h>
using namespace std;
#define int long long int   

const int N = 1e6+5;


vector <bool> primes(N, 1);

void sieve()  {
    primes[0] = primes[1] = 0;
    for(int i=2;i<N;++i) {
          if(primes[i]) {
                for(int j=i*i;j<N;j+=i) {
                    primes[j] = 0;
                }
          }
    }
}


int32_t main()  {

    sieve();

    for(int i=0;i<101;++i)
      if(primes[i])
        cout << i << " ";

    return 0;

}