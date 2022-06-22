#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

template <int MOD>
class Modular {
public:
    Modular(long long v = 0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular expo(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return expo(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend std::istream& operator>>(std::istream &is, Modular& a) {
        is >> a.value;
        a.value %= MOD;
        if (a.value < 0)
            a.value += MOD;
        return is;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    friend Modular& operator++(Modular& a, int) {
        return a += 1;
    }

    friend Modular operator++(Modular const& a, int) {
        return Modular(a)++;
    }

    friend Modular& operator--(Modular& a, int) {
        return a -= 1;
    }

    friend Modular operator--(Modular const& a, int) {
        return Modular(a)--;
    }

    int value;
    static const int MOD_value = MOD;
};

const int mod = 1e9 + 7;
using Mint = Modular<mod>;

vector<Mint> fact, finv;
inline void init(int n) {
    fact.resize(n, Mint(1LL));
    finv.resize(n, Mint(1LL));
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[n - 1] /= fact[n - 1];
    for (int i = n - 2; i >= 2; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}
inline Mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) {
        return Mint(0LL);
    }
    return fact[n] * finv[k] * finv[n - k];
}



int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    init(2005);
    
    cout << C(2000, 1000) << endl;
    
    Mint a = 100000;
    
    cout << expo(a, 10000000);
    
    return 0;
}