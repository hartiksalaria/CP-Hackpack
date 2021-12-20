#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {

private:
	int *parent;
	int *rank;

public:

	DSU(int V)	{

		parent = new int[V];
		rank = new int[V];

		for(int i=0;i<V;++i)	{
			parent[i] = -1;
			rank[i] = 1;
		}

	}

	int findSet(int x)	{
		if(parent[x]==-1)
			return x;
		return parent[x] = findSet(parent[x]);
	}

	void unionSet(int x, int y)	{

		int s1 = findSet(x);
		int s2 = findSet(y);

		if(rank[s1] > rank[s2])	{
			parent[s2] = s1;
			rank[s1] += rank[s2];
		}
		else {
			parent[s1] = s2;
			rank[s2] += rank[s1];
		}

	}

};



class Graph	{

private:

	int V;
	vector <vector <int>> edges;
public:

	Graph(int V)	{
		this->V = V;
	}

	void addEdge(int x, int y, int w)	{
		edges.push_back({w, x, y});
	}


	int mst()	{

		sort(edges.begin(), edges.end());

		int ans = 0;
		DSU s(V);
		for(auto edge: edges)	{

				int w = edge[0];
				int x = edge[1];
				int y = edge[2];

				if(s.findSet(x) != s.findSet(y))	{
					ans += w;
					s.unionSet(x, y);
				}
		}

		return ans;

	}

};



int32_t main()	{

	int n, m;
	cin >> n >> m;

	Graph g(n);
	while(m--)	{

		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		g.addEdge(x, y, w);

	}
	cout << g.mst() << endl;
	return 0;
}
