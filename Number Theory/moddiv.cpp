#include <bits/stdc++.h>
using namespace std;

int expo(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod; 
        a = (a * a) % mod; 
        b = b >> 1;
    } 
    return res;
}

int p = 5;

int moddiv(int a, int b)    {
    return (a*expo(b, p-2, p))%p;
}


int main()  {

    int a, b;
    cin >> a >> b;

    cout << moddiv(a, b) << endl;

    return 0;

}