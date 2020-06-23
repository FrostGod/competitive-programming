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
#define newline cout<<"\n"
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define nax (int)2e5+3
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
		


int n,q;
const int l = 31;


int dp[nax][l];


signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	
	//int val = 1 <<29;
	//deb(val);
	
	for(int i =0 ; i <n ;i++){
		cin >> dp[i+1][0];
	}
	
	for(int i = 1; i < l ; i++){
		for(int j = 1 ; j <= n ;j++){
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}
	
	while(q--){
		int planet,k;
		cin >> planet >> k;
		int ans = planet;
		int val = 0;
		while(k >= 1){
			if(k%2 == 1){
				ans = dp[ans][val];
			}
			val++;
			k /= 2;
				
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}

	

