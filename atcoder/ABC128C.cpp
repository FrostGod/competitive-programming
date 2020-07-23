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


int n , bulbs;
map<int,set<int>> m;
vector<int> decision;

int calc(int idx ,vector<int> state){
	if(idx == n){
		int cnt = 0;
		for(int i =0 ; i < (int)state.size(); i++){
			if(state[i]%2 == decision[i]){
				cnt += 1;
			}
		}
		
		if(cnt == bulbs){
			return 1;
		}
		else{
			return 0;
		}
		
	}
	
	int ans = 0;
	vector<int> new_state = state;
	for(auto it : m[idx]){
		new_state[it] += 1;
	}
	
	ans += calc(idx+1, state);
	ans += calc(idx+1 , new_state);
	
	return ans;
	
	
}

signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	
	cin >> n >> bulbs;
	
	for(int i =0 ; i < bulbs; i++){
		int k;
		cin >> k;
		for(int j =0 ; j< k ; j++){
			int temp;
			cin >> temp;
			m[temp-1].insert(i);
		}
		
	}
	
	for(int i = 0; i <bulbs ;i++){
		decision.pb(-1);
		cin>>decision[i];
	}
	
	vector<int> state(bulbs ,0);
	
	
	int ans = calc(0 ,state);
	
	cout<<ans;
	
	
	return 0;
}
