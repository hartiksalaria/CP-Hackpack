#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct Point {
    int x;
    int y;
    bool operator<(Point p) const {
        if (x == p.x) {
            return y < p.y;
        }
        return x < p.x;
    }
    bool operator==(Point p) const {
        return (x == p.x && y == p.y);
    }
};

istream &operator>>(istream &istream, Point &p) {
    return (istream >> p.x >> p.y);
}

ostream &operator<<(ostream &ostream, Point &p) {
    return (ostream << p.x << " " << p.y);
}

bool clockwise(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
}

bool anticlockwise(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
}

bool collinear(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) == 0;
}

vector<Point> convex_hull(vector<Point> &a) {
    int n = a.size();
    if (n <= 2) {
        return a;
    }
    sort(a.begin(), a.end());
    Point first = a[0], last = a[n - 1];
    vector<Point> up, down;
    up.push_back(first);
    down.push_back(first);
    for (int i = 1; i < n; ++i) {
        if (i == n - 1 || !anticlockwise(first, a[i], last)) {
            while (up.size() >= 2 && anticlockwise(up[up.size() - 2], up[up.size() - 1], a[i])) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (i == n - 1 || !clockwise(first, a[i], last)) {
            while (down.size() >= 2 && clockwise(down[down.size() - 2], down[down.size() - 1], a[i])) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }
    vector<Point> res;
    for (auto p : up) {
        res.push_back(p);
    }
    for (auto p : down) {
        res.push_back(p);
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto res = convex_hull(a);

    cout << res.size() << '\n';
    for (auto p : res) {
        cout << p << '\n';
    }

    return 0;
}