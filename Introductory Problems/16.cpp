#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;
#define int long long
#define loop(i, start, end) for (int i = start; i <= end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define read(a,n) loop(i,0,n-1) cin>>a[i];
#define vi vector<int>
#define vec(x) vector<x>
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define all(v) (v).begin(),(v).end()
#define arl(v) (v).rbegin(),(v).rend()
#define fsp(a) fixed<<setprecision(a)
#define mem(a,with) memset(a, with, sizeof (a))
#define vmn(a) (*min_element(a.begin(),a.end()))   
#define vmx(a) (*max_element(a.begin(),a.end()))
#define bs(a,key) binary_search(all(a),key)    /// return bool.
#define rotl(a,x) rotate(a.begin(),a.begin()+x,a.end());
#define rotr(a,x) rotl(a,a.size()-x);
#define nl cout<<endl
#define dbg(x) cerr << #x << " :: " << x << endl;
#define dbg2(x, y) cerr << #x << " :: " << x << "\t" << #y << " :: " << y << endl;
#define MOD 1000000007
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
 
string s;
int ans;
bool g[7][7];
 
int f(int y, int x, int i, char m) {
  if (i == 48) return 1;
  if (g[6][0]) return 0;
  if (m == 'L' && (x == 0 || g[y][x-1]) && y > 0 && y < 6 && !g[y-1][x] && !g[y+1][x]) return 0;
  if (m == 'R' && (x == 6 || g[y][x+1]) && y > 0 && y < 6 && !g[y-1][x] && !g[y+1][x]) return 0;
  if (m == 'U' && (y == 0 || g[y-1][x]) && x > 0 && x < 6 && !g[y][x-1] && !g[y][x+1]) return 0;
  if (m == 'D' && (y == 6 || g[y+1][x]) && x > 0 && x < 6 && !g[y][x-1] && !g[y][x+1]) return 0;
  if (s[i] == '?') {
    int r[] = {-1, 0, 1, 0};
    int c[] = {0, -1, 0, 1};
    int k = 0;
    for (int j = 0; j < 4; j++) {
      int yy = y + r[j];
      int xx = x + c[j];
      if (yy < 0 || yy > 6) continue;
      if (xx < 0 || xx > 6) continue;
      if (g[yy][xx]) continue;
      g[yy][xx] = true;
      k += f(yy, xx, i + 1, "ULDR"[j]);
      g[yy][xx] = false;
    }
    return k;
  }
  if (s[i] == 'L') x--;
  else if (s[i] == 'R') x++;
  else if (s[i] == 'U') y--;
  else if (s[i] == 'D') y++;
  if (x < 0 || x > 6) return 0;
  if (y < 0 || y > 6) return 0;
  if (g[y][x]) return 0;
  g[y][x] = true;
  int k = f(y, x, i + 1, s[i]);
  g[y][x] = false;
  return k;
}
 
void solve(){
    //code goes here
    cin>>s;
    g[0][0]=1;
    cout<<f(0,0,0,0);
}
 
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
     auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<microseconds>(stop - start);
    cout<<"\n\nExecuted In: "<<duration.count()<<" ms";
#endif
    return 0;
}