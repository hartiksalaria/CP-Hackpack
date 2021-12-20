#include <bits/stdc++.h>
using namespace std;

class Graph	{

public:

	int V;	
	vector <int> *gr;
	int *vis;

	Graph(int V)	{
		this->V = V;
		gr = new vector <int> [V];
		vis = new int [V];
		for(int i=0;i<V;++i)
			vis[i] = false;
	}

	void addEdge(int x, int y)	{
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	bool cycleDetect(int a, int parent)	{

		vis[a] = true;
		for(auto n: gr[a])	{
			if(vis[n] and n!= parent)	
				return true;
			if(!vis[n]){
				bool ans = cycleDetect(n, a);
				if(ans)
					return true;
			}
		}
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
			ans = g.cycleDetect(i, -1);
		}
		if(ans)
			break;
	}

	cout << ans << endl;

	return 0;

}