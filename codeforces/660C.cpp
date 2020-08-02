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


const int nax = 1e5+2;
int n,m;
vector<int> adj[nax];
vector<int> people , h_factor;
vector<int> number;
vector<bool> vis;
bool ans = true;
int dfs(int next){
	vis[next] = true;
	int sum = people[next];
	for(auto it : adj[next]){
		if(vis[it] == false){
			sum += dfs(it);
		}
	}
	
	number[next] = sum;
	return sum;
	
}


int dfs_main(int next){
	vis[next] = true;
	
	int temp = number[next] + h_factor[next];
	
	if(temp%2 == 1 || temp < 0){
		ans = false;
	}
	
	temp = temp/2;
	
	int sad = number[next] - temp;
	
	//debug(next , temp , atleast , sad);
	
	if(sad < 0){
		ans = false;
	}
	
	if((temp - sad) != h_factor[next])
		ans = false;
	
	if(temp + sad != number[next])
		ans = false;
	//debug(next , temp , sad);
	//debug(next ,h_factor[next], sad , atleast);
	
	int atleast = 0;
	if(sad > people[next]){
		atleast = sad - people[next];
	}
	
	int total_sad = 0;
	
	for(auto it : adj[next]){
		if(vis[it] == false){
			total_sad += dfs_main(it);
		}
	}
	
	
	
	if(atleast > total_sad){
		ans = false;
	}
	
	
	
	if(h_factor[next] > 0){
		return sad;
	}
	else
		return sad;
	
}

void solve(){
	cin >> n >> m;
	
	people.assign(n+1 , 0);
	h_factor.assign(n+1, 0);
	number.assign(n+1, 0);
	ans = true;
	
	for(int i =0 ; i < nax; i++){
		vector<int> new_v;
		adj[i] = new_v;
	}
	
	for(int i =1  ; i <= n; i++){
		cin >> people[i];
	}
	for(int i = 1 ; i <= n; i++)cin >> h_factor[i];
	
	for(int i =0 ; i < n -1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	vis.assign(n+1 , false);
	
	dfs(1);
	
	//debug(number);
	
	vis.assign(n+1, false);
	
	dfs_main(1);
	
	if(ans)
		cout<<"YES\n";
		
	else{
		cout<<"NO\n";
	}
	
	
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
