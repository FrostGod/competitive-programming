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

const int mod = 1e9+7;
const int nax = 1e5+2;
vector<int> adj[nax];
int n , primes;
vector<int> values;
vector<bool> leaf ,vis;
vector<int> edge_info;

int dfs(int next){
	bool ok = true;
	vis[next] = ok;
	int num = 0;
	for(auto it : adj[next]){
		if(vis[it] == false){
			int temp = dfs(it);
			edge_info.pb((n - temp)*temp);
			num += temp;
		}
	}
	
	
	if(ok){
		leaf[next]= true;
	}
	
	return num + 1;
}

void solve(){
	cin >> n;
	vector<int> new_v;
	for(int i = 0 ; i < nax ;i++){
		//vector<int> new_v;
		adj[i] = new_v;
	}
	edge_info = new_v;
	values = new_v;
	
	for(int i = 0; i < n - 1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	cin >> primes;
	values.assign(primes , 0);
	for(int i =0 ; i < primes ; i++){
		cin >> values[i];
	}
	sort(all(values));
	
	//reverse(all(values));
	
	vis.assign(n+1 , false);
	leaf.assign(n+1 , false);
	dfs(1);
	//debug(edge_info);
	sort(all(edge_info));
	int ans = 0;
	if(primes >= n - 1){
		//int additional = primes - (n-1);
		//debug(values);
		//debug(edge_info);
		for(int i =0 ; i < n - 2; i++){
			ans = (ans + (edge_info[i]*values[i])%mod)%mod;
		}
		//debug(ans , n-2);
		int val = 1;
		for(int i= n-2 ; i < primes; i++){
			val = (val*values[i])%mod;
		}
		//debug(val);
		ans = (ans + (edge_info[n-2]*val)%mod)%mod;
	}
	else{
		reverse(all(edge_info));
		reverse(all(values));
		//debug(values);
		//debug(edge_info);
		for(int i =0 ; i < primes; i++){
			ans = (ans + (edge_info[i]*values[i])%mod)%mod;
		}
		for(int i = primes ; i < n -1 ; i++){
			ans = (ans + (edge_info[i]*1)%mod)%mod;
		}
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
