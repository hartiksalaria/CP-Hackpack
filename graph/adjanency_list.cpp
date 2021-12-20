#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
#define int long long int
#define ff first
#define ss second

class Graph {

  int V;
  list <int> *l;
public:
  Graph(int v) {

    V = v;
    l = new list <int> [V];

  }


  void addEdge(int i, int j, bool undir = true) {

    l[i].push_back(j);
    if(undir)
      l[j].push_back(i);

  }

  void printGraph() {

    for(int i=1;i<V;++i)  {

      for(auto x:l[i])
        cout<<x<<" ";
      cout << endl;

    }


  }


};



void solve()    {


  Graph g(6);
  g.addEdge(1,5);
  g.addEdge(1,3);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(4,2);
  g.addEdge(4,5);

  g.printGraph();

}

int32_t main()  {

   clock_t begin = clock();
    
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   #endif 

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  // cin >> t;
  while(t--)
    solve();


   #ifndef ONLINE_JUDGE
     clock_t end = clock();
     cout << endl << endl << "Executed in : " << fixed << double(end - begin) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec ";
   #endif 

    return 0;
}