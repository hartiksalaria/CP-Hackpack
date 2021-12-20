#undef _GLIBCXX_DEBUG                
#pragma GCC optimize("Ofast,inline,unroll-loops") 
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                                                       
#pragma GCC target("aes,pclmul,rdrnd")                           
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ckmin min_element
#define ckmax max_element 
#define sz(z) (int)(z).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector <string> vs;
typedef map <int, int> mi;
typedef map <int, string> mis;
typedef map <string, int> msi;
typedef map <string, string> mss;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


#define umi unordered_map <int, int, custom_hash>
#define range(x) for(int i=0;i<x;++i)
#define loop(i,r,l) for(int i=r;i<l;++i)
#define rloop(i,s,e) for (int i=s;i>=e;--i)
#define trav(x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define inf LLONG_MAX
#define ninf LLONG_MIN


/*..............................................................................................................................*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int x) {cerr << x;}
void _print(long x) {cerr << x;}
void _print(unsigned x) {cerr << x;}
void _print(unsigned long x) {cerr << x;}
void _print(unsigned long long x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(long double x) {cerr << x;}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(const char *x) {cerr << '\"' << x << '\"';}
void _print(const string &x) {cerr << '\"' << x << '\"';}
void _print(bool x) {cerr << (x ? "true" : "false");}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


template<typename T1, typename T2> 
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> 
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2> 
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> 
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }


/*..............................................................................................................................*/

int gcd(int a,int b) {if(b==0)return a;return gcd(b, a%b);}
int expo(int a, int n)  {int ans = 1;while(n)  {if(n&1) {ans *= a; }a *= a;n>>=1;}return ans;}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// decreasing by second (increasing by first)

auto comp1 = [](const pair <int, int> &a, const pair <int, int> &b) -> bool {
      return a.ss > b.ss;
};

// increasing by first (decreasing by second)

auto comp2 = [](const pair <int, int> &a, const pair <int, int> &b) -> bool {
        if(a.ff == b.ff)
            return a.ss > b.ss;
        return a.ff < b.ff;
}; 

//  decreasing by first (increasing by second)


auto comp3 = [](const pair <int, int> &a, const pair <int, int> &b) -> bool {
        if(a.ff == b.ff)
            return a.ss < b.ss;
        return a.ff > b.ff;
}; 





/*...........................................................................................................................................................................................................................................................................................*/




bool mutiple_test_case = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MOD = 1000000007;
const int N = 2e5+1;
const ld eps = 1e-9;

void preSolve() {



}



void solve()    {

    

}





/*.............................................................................................................................*/







int32_t main()  {
      

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // #ifndef ONLINE_JUDGE
  //     freopen("input.txt","r",stdin); 
  //     freopen("output.txt","w",stdout);
  //     freopen("error.txt", "w", stderr);
  // #endif


  preSolve();

  int t = 1;
  if(mutiple_test_case)
    cin >> t;

  // int idx = 0;
  while(t--)  {  
    // idx++;
    // cout << "Scenario #" << idx << ":" << endl;
    solve();
  }


   return 0;
}