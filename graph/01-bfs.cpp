#include "bits/stdc++.h"
using namespace std;
#define int long long int 
#define endl "\n"
 
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(x)
#endif
 
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
 
    int tt;
    cin >> tt;
 
    while(tt--){
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int r, c;
        cin >> r >> c;
        const int inf = 1e18;
        vector<vector<char>> grid(r, vector<char> (c));
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                cin >> grid[i][j];
        deque<pair<int,pair<int,int>>> q;
        q.push_front({0, {0, 0}});
        vector<vector<int>> dis(r, vector<int> (c, inf));
        
        while(!q.empty()){
            auto node = q.front();
            q.pop_front();
            int w = node.first;
            int x = node.second.first;
            int y = node.second.second;
            
            for(int i = 0; i < 4; ++i){
                int xx = x + dx[i];
                int yy = y + dy[i];
                
                if(xx < 0 or xx >= r or yy < 0 or yy >= c)  continue;
                if(w + (grid[x][y] != grid[xx][yy]) < dis[xx][yy]){
                    dis[xx][yy] = w + (grid[x][y] != grid[xx][yy]);
                    if(grid[x][y] != grid[xx][yy])
                        q.push_back({dis[xx][yy], {xx, yy}});
                    else 
                        q.push_front({dis[xx][yy], {xx, yy}});
                }
                
            }
            
        }
        cout << dis[r-1][c-1] << endl;
    }
 
    return 0;
} 