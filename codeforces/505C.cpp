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

int n , d;	
map<int , int> jems;

const int max_n = 30000;

int dp[max_n+2][500]; 

int calc(int start ,int len){
	
	
	//debug(start, len);
	if(len >= d){
		int val = abs(len - d);
		if(val > 245)
			return 0;
	}
	
	if(len < d){
		int val = abs(d - len);
		if(val > 245 || len <= 0)
			return 0;
	}
	
		
	if(start > max_n)
		return 0;
	
	
	if(len >= d){
		int val = abs(len - d);
		if(dp[start][val+245] != -1)
			return dp[start][val+245];
	}
	
	if(len < d){
		int val = abs(d - len);
		if(dp[start][val] != -1)
			return dp[start][val];
	}
	
	
	
		
	int ans = 0;
	
	int val1 = calc(start + len , len);
	int val2 = calc(start + (len -1) , len-1);
	int val3 = calc(start + (len+1) , len+1);
	
	ans = max({val1 , val2, val3});
	
	ans += jems[start];
	
	if(len >= d){
		int val = abs(len - d);
		dp[start][val+245] = ans;
	}
	
	if(len < d){
		int val = abs(d - len);
		dp[start][val] = ans;
	}
	
	return ans;
	
	
	
	
}


signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	
	cin >> n >> d;
	
	
	for(int i =0 ; i <= max_n ;i++){
		for(int j = 0; j < 500; j++){
			dp[i][j] = -1;
		}
	}
	
	
	for(int i =0 ; i < n ; i++){
		int temp;
		cin >> temp;
		jems[temp] += 1;
		//last = temp;
	}
	
	
	int ans = calc(d , d);
	
	cout<<ans;
	
	
	return 0;
}
