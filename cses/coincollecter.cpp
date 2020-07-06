#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long 
#include <set>
#include <map>


#define x first
#define y second
#define all(p) p.begin(),p.end()
#define pb push_back
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
 
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
 
 
const int nax = 1e5+2; 
vector<int> adj[nax] , lis , coins ,bad[nax] , new_adj[nax] ,order;
vector<bool> vis;	
int n , m;
vector<int> comp;
map<int,int> build;


void dfs(int next){
	vis[next] = true;
	for(auto it : adj[next]){
		if(vis[it] == false){
			dfs(it);
		}
	}
	lis.pb(next);
}


int dfs2(int next ,int val){
	vis[next] = true;
	int my_val = 0;
	comp[next] = val;
	
	for(auto it : bad[next]){
		if(vis[it] == false){
			my_val += dfs2(it,val);
		}
	}
	return my_val + coins[next];
}


void dfs3(int next){
	vis[next] = true;
	for(auto it : new_adj[next]){
		if(vis[it] == false){
			dfs3(it);
		}
	}
	order.pb(next);
	
}

	
signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	
	cin >> n>> m;
	
	coins.resize(n+1 , 0);
	for(int i = 1; i <=n ;i++)cin>> coins[i];
	
	for(int i =0 ; i< m ; i++){
		int u,v;
		cin>> u >> v;
		adj[u].pb(v);
		bad[v].pb(u);
	}
	
	vis.resize(n+1,false);
	for(int i =1 ; i <= n;i++){
		if(vis[i] == false){
			dfs(i);
		}
	}
	
	reverse(all(lis));
	vis.assign(n+1,false);
	comp.resize(n+1, -1);
	
	int val = 1;
	for(auto it : lis){
		if(vis[it] == false){
			int sum = dfs2(it , val);
			build[val] = sum;
			val += 1;
		}
	}
	
	
	//debug(build);
	//debug(comp);
	
	int new_vertices = val - 1;
	for(int i = 1 ; i<= n ; i++){
		for(auto it : adj[i]){
			if(comp[it] != comp[i]){
				new_adj[comp[i]].pb(comp[it]);
			}
		}
	}
	
	vis.assign(new_vertices+1, false);
	for(int i = 1;  i<= new_vertices; i++){
		if(vis[i] == false){
			dfs3(i);
		}
	}
		
	reverse(all(order));
	
	//debug(order);
	
	vector<int> dp(new_vertices+1, 0);
	
	for(int i = 1 ; i <= new_vertices; i++){
		dp[i]  = build[i];
	}
	
	for(int i = 0; i<new_vertices ;i++){
		int vertex = order[i];
		//debug(vertex);
		for(auto it : new_adj[vertex]){
			//debug(it);
			dp[it] = max(dp[it] , build[it] + dp[vertex]);
		}
	}
	
	//debug(dp);
	
	cout<<*max_element(all(dp));
	
	return 0;
}
