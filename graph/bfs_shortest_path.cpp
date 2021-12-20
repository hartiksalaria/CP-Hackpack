#include <bits/stdc++.h>
using namespace std;

class Graph	{

private:	
	int V;
	vector <int> *gr;
	int *vis;
	int *dis;

public:

	Graph(int V)	{
		this->V = V;
		gr = new vector <int> [V];
		vis = new int [V];
		dis = new int [V];
		for(int i=0;i<V;++i)	{
			vis[i] = false;
			dis[i] = -1;
		}
	}

	void addEdge(int x, int y)	{
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	void shortestPath()	{

		queue <int> q;
		q.push(0);
		dis[0] = 0;
		vis[0] = true;
		while(!q.empty())	{
			int node = q.front();
			q.pop();
			for(auto n: gr[node])	{
				if(!vis[n])	{
					dis[n] = dis[node]+1;
					q.push(n);
					vis[n]=true;
				}
			}
		}
	}

	void display()	{
		for(int i=0;i<V;++i)	
			cout << dis[i] << " ";
		cout << endl;
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

	g.shortestPath();
	g.display();

	return 0;
}
