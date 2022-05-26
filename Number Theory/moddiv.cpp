#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expo(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod; 
        a = (a * a) % mod; 
        b = b >> 1;
    } 
    return res;
}


int moddiv(int a, int b)    {
    return (a * expo(b, mod - 2)) % mod;
}


int main()  {

    int a, b;
    cin >> a >> b;

    cout << moddiv(a, b) << endl;

    return 0;

}