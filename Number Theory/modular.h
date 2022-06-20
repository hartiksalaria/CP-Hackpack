template <int MOD>
class Modular {
// using ModInt = Modular<1000000007>;
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

    friend Modular power(Modular a, long long e) {
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
        return power(a, MOD - 2);
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
using mint = Modular<mod>;