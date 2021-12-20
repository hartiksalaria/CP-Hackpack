#include <bits/stdc++.h>
using namespace std;

class Graph	{

private:
	int V;
	vector <pair <int, int>> edges;
public:

	Graph(int V)	{
		this->V = V;
	}

	void addEdge(int x, int y)	{
		edges.push_back(make_pair(x, y));
	}

	int findSet(int x, vector <int> &parent)	{

		if(parent[x]==-1)
				return x;
		return parent[x] = findSet(parent[x], parent);

	}

	void unionSet(int x, int y, vector <int> &parent, vector <int> &rank)	{

			int s1 = findSet(x, parent);
			int s2 = findSet(y, parent);
			if(rank[s1] > rank[s2])	{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
			else {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}

	}

	bool containsCycle()	{

		vector <int> parent(V, -1);
		vector <int> rank(V, 1);

		for(auto edge: edges)	{

				int x = edge.first;
				int y = edge.second;

				int s1 = findSet(x, parent);
				int s2 = findSet(y, parent);
				if(s1!=s2)	{
					unionSet(x, y, parent, rank);
				}
				else {
					return true;
				}

		}

		return false;

	}

};


int main()	{

	Graph g(5);

	g.addEdge(0, 1);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(0, 4);

	cout << g.containsCycle() << endl;

	return 0;
}

