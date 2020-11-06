#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vec(x) vector<x>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)(x).size()
#define vii vector<pair<int, int>>
#define umpii unordered_map<int, int>
#define mpii map<int, int>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define setBits(n) __builtin_pinitcountint(n)
#define prec(n) fixed << setprecision(n)
#define ff first
#define ss second
#define loop(i, start, end) for (int i = start; i < end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define in(x) cin >> x;
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define printArr(x)   \
    for (auto it : x) \
        cout << it << " ";
#define nl cout << endl
#define dbg(x) cerr << #x << " :: " << x << endl;
#define dbg2(x, y) cerr << #x << " :: " << x << "\t" << #y << " :: " << y << endl;
const int INF = 1e9;
const int mod = 1e9 + 7;
const double pi = acos(-1);
#define EPSILON numeric_limits<double>::epsilon() 
typedef tree<pair <int, int>, null_type, less<pair <int, int>>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int power(int x, int y)
{ 
	if(y==0)return 1;
	int u=power(x,y/2);
	u=(u*u)%mod;
	if(y%2)u=(x*u)%mod;
	return u;
}
int gcd(int a,int b)
{
	if(a<b)return gcd(b,a);
	return (b==0?a:(a%b?gcd(b,a%b):b));
}

int dir[] = {-1, 0, 1, 0, -1};
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

//-------------------------------------------------------------------------------------------------//

//global variables
ordered_set s;

void solve(int tc)
{
	//code here

	int n;
	in(n);

	int arr[n];
	loop(i,0,n) in(arr[i]);

	int dp[n][4];

	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;

	loop(i,1,n){
		loop(j,0,4){
			dp[i][j]=INT_MAX;
			loop(k,0,4){
				int rule=0;
				if(j==k and arr[i]!=arr[i-1]) rule=1;
				if(j>k and arr[i]<=arr[i-1]) rule=1;
				if(j<k and arr[i]>=arr[i-1]) rule=1;

				dp[i][j]=min(dp[i][j],dp[i-1][k]+rule);
			}
		}
	}

	int ans=min({dp[n-1][0],dp[n-1][1],dp[n-1][2],dp[n-1][3]});
    cout << "Case #" << tc << ": " << ans << "\n";
}

int32_t main()
{
    FASTIO;
    int t=1;
    in(t);
    loop(i, 0, t)
    {
        solve(i+1);
    }
    return 0;
}
