//https://www.spoj.com/problems/EC_P/
// https://www.spoj.com/problems/SUBMERGE/

#include "bits/stdc++.h"
using namespace std;

#define int long long int 
#define endl "\n"

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif

const int N = 705;
vector<int> gr[N], dis(N), low(N), vis(N);
int TIME;
set<int> apts;
vector<pair<int, int>> bridges;

void dfs(int node, int parent){
    int child = 0;
    vis[node] = 1;
    dis[node] = low[node] = TIME++;
    for(int nbr: gr[node]){
        if(!vis[nbr]){
            child++;
            dfs(nbr, node);
            low[node] = min(low[node], low[nbr]);
            
            
            // bridge condition
            if(low[nbr] > dis[node])
                bridges.push_back({min(node, nbr), max(node, nbr)});
            
            
            // articulation point condition for all the nodes except the root
            
            if(node != 1 and low[nbr] >= dis[node])
                apts.insert(node);
        }
        else if(nbr != parent){
            
            // backedge in the dfs tree
            low[node] = min(low[node], dis[nbr]);
        }
    }
    
    // treat the root specially for the articulation point 
    // root is articulation point if it has more than one child in the dfs tree
    if(node == 1 and child > 1)
        apts.insert(node);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
        
    int tt;
    cin >> tt;
    
    int idx = 1;
    while(tt--){
        cout << "Caso #" << idx++ << endl;
        int n, m;
        cin >> n >> m;
        TIME = 1;
        apts.clear();
        bridges.clear();
        for(int i = 1; i <= n; ++i){
            gr[i].clear();
            vis[i] = 0;
        }
        while(m--){
            int x, y;
            cin >> x >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        dfs(1, 0);
        
        if(bridges.empty()){
            cout << "Sin bloqueos" << endl;
            continue;
        }
        
        // cout << apts.size() << endl;
        cout << bridges.size() << endl;
        sort(bridges.begin(), bridges.end());
        for(auto [x, y]: bridges)
            cout << x << " " << y << endl;
    }

    return 0;
}