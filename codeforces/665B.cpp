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


void solve(){
	int x1, y1 , z1 ;
	int x2, y2 , z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	
	int ans  = 0;
	if(z1 <= y2){
		ans += z1 * 2;
		y2 -= z1;
		z1 = 0;
	}
	else{
		ans += (y2)*2;
		z1 -= y2;
		y2 = 0;
	}
	if(z1 > z2){
		z1 -= z2;
		z2 = 0;
	}
	else {
		z2 -= z1;
		z1 = 0;	
	}
	if(y1 >= y2){
		y1 -= y2;
		y2 = 0;
	}
	else{
		y2 -= y1;
		y1 = 0;
	}
	if(z2 >= x1){
		z2 -= x1;
	}
	else{
		z2 = 0;
	}
	
	if(z2 >= y1){
		ans -= 2*y1;
	}
	else{
		ans -= 2*z2;
	}
	cout<<ans<<"\n";
	
}

signed main() {    
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	 
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	 
	 
	return 0;
}
