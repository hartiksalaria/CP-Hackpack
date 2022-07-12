// https://codeforces.com/contest/1702/problem/G2

#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

/*

NOTES:

****************************************************************************************************************************************

1. u is ancestor of v if lca(u, v) = u

2. x is in the shortest path from u to v if dis(u, x) + dis(x, v) = dis(u, v) 

****************************************************************************************************************************************

*/

const int N = 2e5 + 5, M = 19;
vector<int> gr[N], dep(N);
vector<vector<int>> par(N, vector<int> (M));

void dfs(int node, int parent) {
    dep[node] = dep[parent] + 1;
    par[node][0] = parent;
    for (int i = 1; i < M; ++i) 
        par[node][i] = par[par[node][i - 1]][i - 1];
    for (int nbr: gr[node]) 
        if (nbr != parent)
            dfs(nbr, node);
}

int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v];
    for (int i = M - 1; i >= 0; --i)
        if ((1LL << i) & diff)
            u = par[u][i];
    if (u == v) 
        return u;
    for (int i = M - 1; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dis(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    dfs(1, 0);
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> nodes(k);
        for (int i = 0; i < k; ++i)
            cin >> nodes[i];
        sort(nodes.begin(), nodes.end(), [&](int i, int j) {
            return dep[i] > dep[j]; 
        });
        
        int u = nodes[0], v = -1;
        for (int i = 1; i < k; ++i) {
            int _lca = lca(u, nodes[i]);
            if (_lca != nodes[i]) {
                v = nodes[i];
                break;
            }
        }
        
        bool ok = true;
        if (v != -1) {
            for (int i = 0; i < k; ++i) {
                if (dis(u, v) != dis(nodes[i], u) + dis(nodes[i], v)) {
                    ok = false;
                    break;
                }
            }
        }
        
        
        cout << (ok ? "YES" : "NO") << endl;
        
    }

    return 0;
}