#include <bits/stdc++.h>
using namespace std;

class Graph	{

private:	
	int V;
	vector <int> *gr;

public:

	Graph(int V)	{
		this->V = V;
		gr = new vector <int> [V];
	}

	void addEdge(int x, int y)	{
		gr[x].push_back(y);
	}

	vector <int> topSort()	{

		vector <int> ans;
		vector <int> in(V, 0);
		queue <int> q;
		for(int i=0;i<V;++i)	{
			for(auto a: gr[i])	{
				in[a]++;
			}
		}

		for(int i=0;i<V;++i)	{
			if(in[i]==0)
				q.push(i);
		}

		while(!q.empty())	{
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for(auto a: gr[node])	{
				in[a]--;
				if(in[a]==0)
					q.push(a);
			}
		}
		return ans;
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

	vector <int> ans = g.topSort();
	for(auto a: ans)
			cout << a << " ";
	cout << endl;

	return 0;
}
