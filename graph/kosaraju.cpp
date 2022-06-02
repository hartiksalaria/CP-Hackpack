#include "bits/stdc++.h"
using namespace std;
#define int long long int 
#define endl "\n"

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif

const int N = 1e4 + 5;
vector<int> gr[N], grr[N];
vector<int> vis(N), order;

// topological sorting 
void dfs1(int node) {
    vis[node] = 1;
    for (int nbr: gr[node]) {
        if (!vis[nbr]) {
            dfs1(nbr);
        }
    }
    order.push_back(node);
}

/*


    starting from the first not yet visited node in the topological ordering 
    do a dfs on it in the reversed graph
    
    source in the original graph is sink in the reversed graph


*/

vector<int> col(N);             // for storing which component a node belong to 
vector<int> components[N];      // for storing which nodes are in a component 

void dfs2(int node, int comp) {
    vis[node] = 1;
    
    components[comp].push_back(node);
    col[node] = comp;
    
    for (int nbr: grr[node]) {
        if (!vis[nbr]) {
            dfs2(nbr, comp);
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);     // normal graph
        grr[y].push_back(x);    // reversed graph
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    
    reverse(order.begin(), order.end());
    
    for (int i = 1; i <= n; ++i)
        vis[i] = 0;
    
    int comp = 1;
    
    for (int x: order) {
        if (!vis[x]) {
            dfs2(x, comp++);
        }
    }
    
    cout << "total components are : " << comp - 1 << endl;
    
    for (int i = 1; i <= n; ++i)
        cout << i << " " << col[i] << endl;
    
    for (int i = 1; i < comp; ++i) {
        debug(components[i]);
    }

    return 0;
}