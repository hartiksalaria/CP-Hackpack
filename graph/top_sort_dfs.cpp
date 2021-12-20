#include <bits/stdc++.h>
using namespace std;

class Graph	{

public:

	int V;	
	vector <int> *gr;
	int *vis;

	list <int> topSort;
	Graph(int V)	{
		this->V = V;
		gr = new vector <int> [V];
		vis = new int [V];
		for(int i=0;i<V;++i)
			vis[i] = false;
	}

	void addEdge(int x, int y)	{
		gr[x].push_back(y);
	}

	void dfsTop(int a)	{

			vis[a] = true;
			for(auto n: gr[a])	{
				if(!vis[n])	{
					dfsTop(n);
				}
			}
		topSort.push_front(a);
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

	for(int i=0;i<g.V;++i)	{
		if(!g.vis[i])	{
			g.dfsTop(i);
		}
	}

	for(auto a: g.topSort)
		cout << a << " ";
	cout << endl;

}