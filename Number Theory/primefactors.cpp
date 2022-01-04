#include <bits/stdc++.h>
using namespace std;



vector <int> factors(int n) {

    vector <int> fac;

    if(n%2 == 0)  {
          fac.push_back(2);
          while(n%2==0) {
            n >>= 1;
          }

    }


    if(n%3 == 0)  {
          fac.push_back(3);
           while(n%3==0) {
             n /= 3;
          }
    }

    for(int i=5;i*i<=n;i+=6) {


          if(n%(i) == 0)  {
                fac.push_back(i);
                while(n%i == 0) {
                    n /= i;
                }
          }


          if(n%(i+2) == 0)  {
                fac.push_back(i+2);
                while(n%(i+2)==0) {
                  n /= (i+2);
                }
          }

    }

    if(n > 4)
      fac.push_back(n);

    return fac;

}


int main()  {

    int n;
    cin >> n;

    vector <int> fac = factors(n);

    for(auto a: fac)
        cout << a << " ";


    return 0;

}