#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

// returns the longest proper prefix array of pattern p
// where lps[i]=longest proper prefix which is also suffix of p[0...i]
vector<int> build_lps(string p) {
    int sz = p.size();
    vector<int> lps;
    lps.assign(sz + 1, 0);
    int j = 0;
    lps[0] = 0;
    for (int i = 1; i < sz; i++) {
        while (j >= 0 && p[i] != p[j]) {
            if (j >= 1)
                j = lps[j - 1];
            else
                j = -1;
        }
        j++;
        lps[i] = j;
    }
    return lps;
}
vector<int> ans;
// returns matches in vector ans in 0-indexed
void kmp(vector<int> lps, string s, string p) {
    int psz = p.size(), sz = s.size();
    int j = 0;
    for (int i = 0; i < sz; i++) {
        while (j >= 0 && p[j] != s[i])
            if (j >= 1)
                j = lps[j - 1];
            else
                j = -1;
        j++;
        if (j == psz) {
            j = lps[j - 1];
            // pattern found in string s at position i-psz+1
            ans.push_back(i - psz + 1);
        }
        // after each loop we have j=longest common suffix of s[0..i] which is also prefix of p
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    vector<int> lps = build_lps(t);
    kmp(lps, s, t);

    cout << ans.size() << '\n';

    return 0;
}

// https://cses.fi/problemset/task/1753