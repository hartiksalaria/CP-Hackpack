#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX

vector <vector <int>> floydWarshall(vector <vector<int>> &gr)    {
    vector <vector <int>> dp(gr);
    int V = gr.size();
    for(int k=0;k<V;++k)    {
        for(int i=0;i<V;++i)    {
            for(int j=0;j<V;++j)    {
                if(dp[i][k] != inf and dp[k][j] != inf)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp;
}


int main()  {

    vector <vector <int>> gr = {
        {0, inf, -2, inf},
        {4, 0, 3, inf},
        {inf, inf, 0, 2},
        {inf, -1, inf, 0}
    };

    auto res = floydWarshall(gr);
    for(auto a: res)    {
        for(auto b: a)
            cout << b << " ";
        cout << endl;
    }

    return 0;

}