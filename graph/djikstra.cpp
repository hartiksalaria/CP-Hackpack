#include <bits/stdc++.h>
using namespace std;

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

   void shortestPath(int src)   {

        set <pair <int, int>> s;
        vector <int> dis(V, INT_MAX);

        s.insert(make_pair(0, src));
        dis[src] = 0;
        while(!s.empty())   {

            auto it = s.begin();
            int disTillNow = it->first; 
            int node = it->second;
            s.erase(it);

            for(auto nbrPair: gr[node]) {

                    int nbr = nbrPair.second;
                    int currDis = nbrPair.first;

                    if(currDis + disTillNow < dis[nbr]) {

                        auto f = s.find(make_pair(dis[nbr], nbr));
                        if(f != s.end())    {
                            s.erase(f);
                        }
                        dis[nbr] = currDis + disTillNow;
                        s.insert(make_pair(dis[nbr], nbr));
                    }
            }

        }

        for(int i=0;i<V;++i)    
            cout << "Node i" << i << " distance " << dis[i] << endl;

   }

};


int main()  {

    int n, m;
    cin >> n >> m;

    Graph g(n);
    while(m--)  {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }

    g.shortestPath(0);

    return 0;
}
