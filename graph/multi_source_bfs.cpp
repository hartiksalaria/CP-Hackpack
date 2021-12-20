#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()  {

 	int n, m;
 	cin >> n >> m;

 	vector <vector <int>> grid(n, vector <int> (m)), dis(n, vector <int> (m));
 	queue <pair <int, int>> Q;
 	for(int i=0;i<n;++i)	{
 		for(int j=0;j<m;++j)	{
 			cin >> grid[i][j];
 			dis[i][j] = INT_MAX;
 			if(grid[i][j])   {
 				Q.push({i, j});
 				dis[i][j] = 0;
 			}
 		}
 	}

 	while(!Q.empty())	{
 		int x = Q.front().first;
 		int y = Q.front().second;
 		Q.pop();

 		for(int i=0;i<4;++i)	{
 			int xx = x + dx[i];
 			int yy = y + dy[i];
 			if(xx >= 0 and xx < n and yy >= 0 and yy < m and dis[xx][yy] == INT_MAX)	{
 				dis[xx][yy] = 1 + dis[x][y];
 				Q.push({xx, yy});
 			}
 		}

 	}

 	for(int i=0;i<n;++i)	{
 		for(int j=0;j<m;++j)	{
 			cout << dis[i][j] << " ";
 		}
 		cout << endl;
 	}

    return 0;

}