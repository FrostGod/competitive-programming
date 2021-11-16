#include <iostream> 
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>  
#include <math.h>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cstring>
#include <cassert>


#define pb push_back
#define int long long
#define ll long long
#define x first
#define y second
#define all(x) x.begin(),x.end()

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

const int inf = (ll)1e18 + 5ll;
const int mod =   (int)998244353;


int power(int a, int b){
	int ans =1ll;
	while(b > 0){
		if(b%2ll == 1ll){
			ans = (ans * a)%mod;
		}

		a = (a * a)%mod;
		b /= 2ll;
	}
	return ans;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

const int nax = 52;
vector<int> adj[nax];
vector<bool> vis(nax, false);
vector<int> par(nax), cost(nax, 0);

int n;
vector<int> leaves;

void dfs(int next, int p, int val){
	vis[next] = true;
	cost[next] = val + cost[next];
	par[next] = p;
	bool leaf = true;
	for(auto it : adj[next]){
		if(vis[it] == false){
			leaf = false;
			dfs(it, next, cost[next]);
		}
	}

	if(leaf){
		leaves.pb(next);
	}

}

void solve(){
	// clear section
	leaves.clear();
	for(int i =0;i<nax; i++){
		adj[i].clear();
		vis[i] = false;
	}

	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> cost[i];
	}

	for(int i=0; i<n-1; i++){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1, 1, 0);

	if(leaves.size() == 1){
		cout << cost[leaves[0]] << "\n";
		return ;
	}


	int ans = 0;
	for(auto it : leaves){
		int val = cost[it];
		int temp = 0;
		for(auto ip : leaves){
			if(it == ip){
				continue;
			}

			int a = it;
			int b = ip;

			set<int> s;
			while(a != 1){
				s.insert(a);
				a = par[a];
			}

			bool poss = true;

			while(b != 1){
				if(s.find(b) != s.end()){
					poss = false;
					break;
				}
				b = par[b];
			}

			if(!poss){
				continue;
			}

			temp = max(cost[ip] - cost[1], temp);
		}

		ans = max(ans, val + temp);
	}

	cout << ans << "\n";

}

signed main(){

	freopen("FB/gold_mine_chapter_1_input.txt", "r", stdin);
	freopen("FB/C1.txt", "w", stdout);

	int t;
	cin >> t;
	int cnt = 1;
	while(t--){
		cout << "Case #"<<cnt<<": ";
		solve();
		cnt += 1;
	}
	
	return 0;
}
