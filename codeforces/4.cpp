#include <bits/stdc++.h> 
#include<cmath>
#include<string>
#define pb push_back
#define x first
#define y second
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
 
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


int n;
const int nax = 3e5 + 2;
vector<int> adj[nax];
vector<int> color;
int reds =0, blues=0;
vector<bool> vis;
int ans = 0;

pair<int,int> dfs(int next){
	vis[next] = true;
	
	int red = 0, blue = 0;
	for(auto it : adj[next]){
		if(vis[it] == false){
			pair<int,int> p = dfs(it);
			red += p.x;
			blue += p.y;
			int rem_red = reds - p.x;
			int rem_blue = blues - p.y;
			//debug(next , it , p , rem_red , rem_blue);
			if(p.x > 0 && p.y >0){
				ans += 1;
			}
			else if(rem_red > 0 && rem_blue>0){
				ans += 1;
			}
			
		}
	}
	
	if(color[next] == 1){
		red += 1;
	}
	else if(color[next] == 2){
		blue += 1;
	}
	
	return {red , blue};
	
		
}


signed main() {    
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> n;
	
	color.assign(n+1 , 0);
	for(int i =1 ; i <= n; i++){
		cin >> color[i];
		if(color[i] == 1)
			reds += 1;
		else if(color[i] == 2){
			blues += 1;
		}
	}
	//debug(reds , blues);
	for(int i =0 ; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	vis.assign(n+1 , false);
	
	dfs(1);
	cout<<n - 1 - ans;
	 
	return 0;
}
