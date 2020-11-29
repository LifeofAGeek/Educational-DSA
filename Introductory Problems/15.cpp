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
 
const int N=8;
char grid[N][N];
int ans;
 
bool isValid(int r,int c){
	// blocked
	if(grid[r][c]=='*'){
		return false;
	}
	//check same col
	for(int i=0;i<N;i++){
		if(grid[i][c]=='q') return false;
	}
	//check negative slope
	for(int i=r,j=c;i>=0 and j>=0;j--,i--){
		if(grid[i][j]=='q') return false;
	}
	//check +ve slope
	for(int i=r,j=c;i>=0 and j<N;j++,i--){
		if(grid[i][j]=='q') return false;	
	}
	return true;
}
 
void f(int row){
	if(row==N){ // base case
		ans++;
		return;
	}
 
	loop(col,0,N-1){ // each cols
		if(isValid(row,col)){
			grid[row][col]='q';
			f(row+1);
			grid[row][col]='.';
		}
	}
}
 
 
void solve(){
    //code goes here
    loop(i,0,N-1) loop(j,0,N-1) cin>>grid[i][j];
    f(0);
    cout<<ans;
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