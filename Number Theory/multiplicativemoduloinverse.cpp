#include <bits/stdc++.h>
using namespace std;


vector <int> extendedGCD(int a, int b)  {

    if(b==0)  {
          return {1, 0, a};
    }

    vector <int> res = extendedGCD(b, a%b);

    int x1 = res[0];
    int y1 = res[1];
    int gcd = res[2];

    int x = y1;
    int y = x1 - (a/b)*y1;

    return {x, y, gcd};

}


int multiMODinverse(int a, int m) {

    vector <int> res = extendedGCD(a, m);

    int ans = res[0];
    int gcd = res[2];

    if(gcd != 1)  {
          cout << "Multiplicative mod inverse doesn't exist !" << endl;
          return -1;
    }

    ans = (ans%m + m)%m;        // to handle negative values
    return ans;

}


int main()  {

    int a, m;
    cin >> a >> m;

    cout << multiMODinverse(a, m) << endl;
    
    return 0;

}