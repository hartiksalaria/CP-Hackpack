#include <bits/stdc++.h>
using namespace std;

class Graph	{

public:

	int V;	
	vector <int> *gr;
	int *vis;
	int *path;

	Graph(int V)	{
		this->V = V;
		gr = new vector <int> [V];
		vis = new int [V];
		path = new int [V];
		for(int i=0;i<V;++i){
			vis[i] = false;
			path[i] = false;
		}
	}

	void addEdge(int x, int y)	{
		gr[x].push_back(y);
	}

	bool containsCycle(int a)	{

		vis[a] = true;
		path[a] = true;

		for(auto n : gr[a])	{
			if(vis[n] and path[n])
				return true;
			if(!vis[n])	{
				bool ans = containsCycle(n);
				if(ans)
					return true;
			}
		}
		path[a] = false;
		return false;

	}


};



int main()	{


	int n, m;
	cin >> n >> m;

	Graph g(n);

	while(m--)	{
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}

	bool ans = false;

	for(int i=0;i<n;++i)	{
		if(!g.vis[i])	{
			ans = g.containsCycle(i);
		}
		if(ans)
			break;
	}

	cout << ans << endl;
}