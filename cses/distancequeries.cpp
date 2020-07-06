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
 

int l = 30; 
const int nax = (int)2e5 + 2;
int n,q;
vector<int> adj[nax];
int timer = 0;
vector<vector<int>> dist(nax,vector<int>(30 , 1)); 
vector<bool> vis;
vector<int> in,out;
vector<int> depth;

void dfs(int next ,int parent){
	
	//debug(next, parent);
	
	vis[next] = true;
	dist[next][0] = parent;
	
	in[next] = timer;
	timer += 1;
	
	for(int i =1 ; i < l ;i++){
		dist[next][i] = dist[dist[next][i-1]][i-1];
	}
	
	for(auto it : adj[next]){
		if(vis[it] == false){
			dfs(it , next);
		}
	}
	
	out[next] = timer;
	timer += 1;
	
}


void dfsdepth(int next ,int val){
	vis[next] = true;
	depth[next] = val;
	for(auto it : adj[next]){
		if(vis[it] == false){
			dfsdepth(it , val+1);
		}
	}
}

bool is_ancestor(int u , int v){
	return (in[u] <= in[v] && out[u] >= out[v]);
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l-1; i >= 0; --i) {
        if (!is_ancestor(dist[u][i], v))
            u = dist[u][i];
    }
    return dist[u][0];
}


void preprocess(){
	
	in.resize(n+1);
	out.resize(n+1);
	vis.resize(n+1 , false);
	dfs(1 , 1);
	depth.resize(n+1);
	depth[1] = 0;
	vis.assign(n+1 , false);
	dfsdepth(1 , 1);
	
}

	
signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	cin >> n >> q;
	for(int i =0 ; i < n -1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	preprocess();
	
	while(q--){
		int node1, node2;
		cin >> node1 >> node2;
		
		int node = lca(node1 ,node2);
		
		int ans = depth[node1] + depth[node2] - 2*depth[node];
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
