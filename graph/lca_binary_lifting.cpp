#include "bits/stdc++.h"
using namespace std;
#define int long long int 
#define endl "\n"

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif

const int N = 1e5 + 5, M = 17;
vector<int> gr[N], dep(N);
vector<vector<int>> par(N, vector<int> (M));


void dfs(int node, int parent) {
    dep[node] = dep[parent] + 1;
    
    par[node][0] = parent;
    for (int i = 1; i < M; ++i)
        par[node][i] = par[par[node][i - 1]][i - 1];
    
    for (int x: gr[node]) {
        if (x != parent) {
            dfs(x, node);
        }
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v];
    
    for (int i = M - 1; i >= 0; --i) {
        if ((1LL << i) & diff) {
            u = par[u][i];
        }
    }
    
    if (u == v) {
        return v;
    }
    
    for (int i = M - 1; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    return par[u][0];

}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
    }
    
    dfs(1, 0);
    
    int q;
    cin >> q;
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }

    return 0;
}
