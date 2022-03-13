#include <bits/stdc++.h>
#define int long long int 
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif


const int inf = 1e18;

class Graph {

private:    
    int V;
    vector <pair <int, int>> *gr;

public:

    Graph(int V)    {
        this->V = V;
        gr = new vector <pair <int, int>> [V];
    }

    void addEdge(int x, int y, int w)  {
        gr[x].push_back(make_pair(w, y));
        gr[y].push_back(make_pair(w, x));
    }

   vector<int> shortestPath(int s)   {

        int nodes = V;
        vector<int> dist(nodes, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[s] = 0;
        q.push({0, s});
        while(!q.empty()){
            auto [dis, node] = q.top();
            q.pop();
            if(dis != dist[node]) continue;
            for(auto [y, w]: gr[node]){
                if(dist[y] > dis + w){
                    dist[y] = dis + w;
                    q.emplace(dist[y], y);
                }
            }
        }
        return dist;

   }

};


int32_t main()  {

    int n, m;
    cin >> n >> m;

    Graph g(n);
    while(m--)  {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }

    auto v = g.shortestPath(0);
    
    debug(v);

    return 0;
}
