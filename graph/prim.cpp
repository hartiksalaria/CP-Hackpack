#include <bits/stdc++.h>
using namespace std;
#define int long long
class Graph	{

private:
	int V;
	vector <pair<int, int>> *gr;

public:

	Graph(int V)	{
		this->V = V;
		gr = new vector <pair <int, int>> [V];
	}

	void addEdge(int x, int y, int w)	{
		gr[x].push_back(make_pair(y, w));
		gr[y].push_back(make_pair(x, w));
	}

	int mst()	{
		int ans=0;

		priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> Q;
		Q.push(make_pair(0, 0));
			
		vector <bool> inc(V, false);

		while(!Q.empty())	{

			int weight = Q.top().first;
			int node = Q.top().second;
			Q.pop();
			if(inc[node])	continue;
			ans += weight;
			inc[node] = true;
			for(auto a: gr[node])	{
				if(!inc[a.first])	
					Q.push(make_pair(a.second, a.first));
			}

		}
		
		return ans;
	}

};


int32_t main()	{

	int n;
	cin >> n;
	Graph g(n);
	int m;
	cin >> m;

	while(m--)	{
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		g.addEdge(x, y, w);
	}

	cout << g.mst() << endl;

	return 0;

}