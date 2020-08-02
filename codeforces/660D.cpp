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

const int nax = 2e5+2;
vector<int> adj[nax];
vector<bool> vis;

vector<int> lis;

void dfs(int next){
	vis[next] = true;
	for(auto it : adj[next]){
		if(vis[it] == false){
			dfs(it);
		}
	}
	lis.pb(next);
	return ;
}

signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> a(n+1),b(n+1);
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i =1 ;i <= n;i++){
		cin >> b[i];
		if(b[i] != -1){
			adj[i].pb(b[i]);
		}
	}
	
	vis.assign(n+1 , false);
	
	for(int i = 1 ; i <= n; i++){
		if(vis[i] == false){
			dfs(i);
		}
	}
	
	
	int ans = 0;
	
	//debug(lis);
	
	reverse(lis.begin() , lis.end());
	
	vector<int> order, not_now;
	
	for(auto it : lis){
		if(a[it] > 0){
			for(auto ip : adj[it]){
				a[ip] += a[it];
			}
			order.pb(it);
		}
		else{
			not_now.pb(it);
		}
		ans += a[it];
	}
	
	cout<<ans<<"\n";
	for(auto it : order){
		cout<<it<<" ";
	}
	reverse(all(not_now));
	for(auto it : not_now){
		cout<<it<<" ";
	}
	
	return 0;
}
