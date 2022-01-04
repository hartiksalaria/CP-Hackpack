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


int main()  {

    int a, b;
    cin >> a >> b;

    // ax + by = gcd(a, b)

    vector <int> res = extendedGCD(a, b);

    cout << res[0] << " " << res[1] << " : " << res[2] << endl;

    return 0;

}