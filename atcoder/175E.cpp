#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<cmath>
#include<string>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define deb(x) cerr<<#x<<" "<<x<<"\n"
#define debi cerr<<"hey sparky\n"
#define x first
#define y second
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define eps (double)1e-9
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
using namespace __gnu_pbds; 
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pdbs;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
//void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
// look for  all edge cases
//search for a pattern
 
int r , c , k;

int m[3002][3002];

int dp[3002][3002][4];

int calc(int row , int col , int  picked){
	
	
	if(dp[row][col][picked] != -1){
		return dp[row][col][picked];
	}
	
	int val = 0;
	
	if(row < r){
		int dummy = calc(row + 1 , col , 0);
		int cnt = picked;
		//debug(picked);
		//int now = 0;
		//int sum = 0;
		if(cnt < 3)
			val = max(val , calc(row + 1, col ,0 ) + m[row][col]);
		
		val = max(dummy , val);
	}
	if(col < c){
		val = max(val , calc(row , col+1 , picked));
		//int now = 0;
		//int sum = 0;
		int cnt = picked;
		if(cnt  < 3)
			val = max(val , calc(row , col+1 , picked +1 ) + m[row][col]);
	}
	
	if(row == r && col == c){
		//int now = 0;
		int sum = 0;
		//int cnt = picked;
		if(picked < 3)
			sum += m[row][col];
		val = max(val , sum);
	}
	
	
	//debug(row , col , val);
	dp[row][col][picked] = val;
	
	return val;
}


signed main() {
	
	cin >> r >> c >> k;
	for(int i =0 ;  i < k ; i++){
		int temp1 , temp2 , val;
		cin >> temp1 >> temp2 >> val;
		m[temp1][temp2] = val;
	}
	
	
	for(int i =0 ; i < 3001 ; i++){
		for(int j = 0; j < 3001; j++){
			for(int p =0 ; p < 4 ;p++){
				dp[i][j][p] = -1;
			}
		}
	}
	
	int ans = calc(1  , 1 , 0);
	
	cout<<ans; 
   
   return 0;
}
