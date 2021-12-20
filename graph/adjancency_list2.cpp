#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
#define int long long int
#define ff first
#define ss second


class Node {

public:

  string name;
  list <string> l;


  Node(string s) {

    name = s;

  }

};


class Graph {

public:

  unordered_map <string, Node *> mp;

  Graph(vector <string> s) {

    for(auto city:s)  {

      Node *n = new Node(city);
      mp[city] = n;

    }

  }

  void addEdge(string x, string y, bool undir = false)  {


    mp[x]->l.push_back(y);

    if(undir)
      mp[y]->l.push_back(x);


  }



  void printGraph() {


    for(auto a : mp)  {


      cout << a.first <<"-> ";

      for(auto s : a.second->l)
        cout<<s<<",";
      cout << endl;


    }

  }


};


void solve() {

  vector <string> cities = {"london", "delhi", "paris", "madrid"};


  Graph g(cities);


  g.addEdge("paris", "london");
  g.addEdge("delhi", "paris");
  g.addEdge("madrid", "delhi");
  g.addEdge("madrid", "paris");
  g.addEdge("delhi", "london");


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