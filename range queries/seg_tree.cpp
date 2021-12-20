#include <bits/stdc++.h>
using namespace std;

struct seg {

	vector <int> st;
	int n;

	void init(int n)	{
		this->n = n;
		st.resize(4*n, 0);
	}

	void build(int start, int end, int node, vector <int> &v)	{

		if(start == end)	{
			st[node] = v[start];
			return;
		}

		int mid = (start+end)/2;

		build(start, mid, node*2+1, v);
		build(mid+1, end, node*2+2, v);

		st[node] = st[node*2+1] + st[node*2+2];

	}

	void build(vector <int> &v)	{
		build(0, n-1, 0, v);
	}


	int query(int start, int end, int l, int r, int node)	{

		if(l > end or r < start)	{
			return 0;
		}

		if(l <= start and r >= end)	{
			return st[node];
		}

		int mid = (start+end)/2;

		int q1 = query(start, mid, l, r, node*2+1);
		int q2 = query(mid+1, end, l, r, node*2+2);

		return q1+q2;

	}

	int query(int l, int r)	{
		return query(0, n-1, l, r, 0);
	}

	void update(int start, int end, int pos, int x, int node)	{

		if(start == end)	{
			st[node] = x;
			return;
		}

		int mid = (start+end)/2;
		if(pos <= mid)	{
			update(start, mid, pos, x, node*2+1);
		}
		else {
			update(mid+1, end, pos, x, node*2+2);
		}

		st[node] = st[node*2+1] + st[node*2+2];

	}

	void update(int pos, int x)	{
		update(0, n-1, pos, x, 0);
	}
};


int main()  {

	int n, m;
	cin >> n >> m;
	vector <int> v(n);

	for(int i=0;i<n;++i)
		cin >> v[i];

	seg s;
	s.init(n);
	s.build(v);


	for(int i=0;i<m;++i)	{
		int x, y;
		cin >> x >> y;

		x--;
		y--;
		cout << s.query(x, y) << endl;
	}
	

    return 0;

}