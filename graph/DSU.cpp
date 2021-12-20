#include <bits/stdc++.h>
using namespace std;


class Graph	{

private:
	int V;
	vector <pair<int, int>> edges;

public:

	Graph(int V)	{
		this->V = V;
	}

	void addedge(int x, int y)	{
		edges.push_back(make_pair(x, y));
	}

	int findSet(int a, vector <int> &parent)	{

		if(parent[a] == -1)	
			return a;	
		return findSet(parent[a], parent);

	}

	void unionSet(int x, int y, vector <int> &parent)	{

		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		if(s1!=s2)	
			parent[s2] = s1;
	}



	bool containsCycle()	{

		vector <int> parent(V, -1);
		for(auto edge: edges)	{
			int x=edge.first;
			int y=edge.second;

			int s1=findSet(x, parent);
			int s2=findSet(y, parent);

			if(s1!=s2)	{
				unionSet(x, y, parent);
			}
			else {
				cout << "same parents " << s1 << " " << s2 << endl;
				return true;
			}

		}
		return false;
	}

	void debug()	{
			for(auto edge:edges)
				cout << edge.first << "<->" << edge.second << endl;
	}

};




int main()	{

	Graph g(5);
	g.addedge(0, 1);
	g.addedge(1, 2);
	g.addedge(2, 3);
	g.addedge(3, 4);
	g.addedge(4, 0);

	// g.debug();

	cout << g.containsCycle() << endl;

	return 0;
}