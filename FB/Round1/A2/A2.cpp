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

vector<int> adj[26];
vector<vector<int>> dis;

void bfs(char c){
	vector<int> this_dis(26, inf);
	this_dis[c - 'A'] = 0;
	vector<bool> vis(26, false);
	queue<int> q;
	q.push(c-'A');

	while(!q.empty()){
		int next = q.front();
		q.pop();
		vis[next] = true;
		for(auto it : adj[next]){
			if(vis[it] == false){
				this_dis[it] = min(this_dis[it], this_dis[next] + 1);
				q.push(it);
			}
		}
	}

	dis.pb(this_dis);

}

void solve(){

	//TODO: Clear section 
	for(int j=0; j<26; j++){
		adj[j].clear();
	}
	vector<vector<int>> new_dis;
	dis = new_dis; 

	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();

	for(int i=0; i<k; i++){
		string temp;
		cin >> temp;
		int u = temp[0] - 'A';
		int v = temp[1] - 'A';
		adj[u].pb(v);
	}

	for(int i =0; i<26; i++){
		bfs(i+'A');
	}

	int ans = inf;
	for(int i =0; i<26; i++){
		int cost = 0;
		for(int j=0; j<n; j++){
			int p = s[j] - 'A';
			if(i == p){
				continue;
			}
			int val = dis[p][i];
			if(val == inf){
				cost = inf;
				break;
			}
			cost += val;
		}
		ans = min(cost, ans);
	}

	if(ans == inf)
		ans = -1;

	cout << ans << "\n";	

}

signed main(){

	freopen("FB/consistency_chapter_2_input.txt", "r", stdin);
	freopen("FB/A2.txt", "w", stdout);

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
