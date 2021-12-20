#include <bits/stdc++.h>
using namespace std;


 vector <int> bellman_ford(int V, int src, vector <vector <int>> &edges)	{

 		vector <int> dis(V+1, INT_MAX);
 		dis[src] = 0;

 		for(int i=0;i<V-1;++i)	{

 			for(auto edge : edges)	{

 					int u = edge[0];
 					int v = edge[1];
 					int wt = edge[2];

 					if(dis[u] != INT_MAX and dis[u] + wt < dis[v])	{
 						dis[v] = dis[u] + wt;
 					} 

 			}

 		}

 		// for detecting negative weight cycle 

 		for(auto edge : edges)	{

 					int u = edge[0];
 					int v = edge[1];
 					int wt = edge[2];

 					if(dis[u] != INT_MAX and dis[u] + wt < dis[v])	{
 						cout << "negative weight cycle";
 						exit(0);
 					} 

 		}

 		return dis;

 }


void solve()    {

	vector <vector <int>> edges;
	int n, m;
	cin >> n >> m;

	while(m--)	{
		int x, y, wt;
		cin >> x >> y >> wt;
		edges.push_back({x, y, wt});
	}	

	vector <int> dis = bellman_ford(n, 1, edges);

	for(int i=1;i<=n;++i)	{
		cout << "distance to " << i << " is " << dis[i] << endl;
	}

}


int main()  {

    int t=1;
    cin >> t;

    while(t--)
        solve();

    return 0;

}