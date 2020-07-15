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


int n,target;
vector<int> plu;
vector<int> minu ;
vector<int> v;
bool possible = false;

// 1->addition 2-> sub

const int max_n = 2*40*1000 + 2;
int dp[42][max_n];


bool calc(int idx , int val){
	
	if(dp[idx][val+40*1000] != -1)
		return dp[idx][val+40*1000];
	
	if(idx == n){
		if(val == target){
			possible = true;
			return true;
		}
		else
			return false;
	}
	
	
	bool ans = false;
	
	bool val1 = calc(idx+1 , val+v[idx]);
	bool val2 = calc(idx+1 , val-v[idx]);
	if(val1 == true)
		plu[idx] = 1;
	if(val2 == true)
		minu[idx] = 1;
	
	
	ans = val1|val2;
	dp[idx][val+40*1000] = ans;
	
	
	return ans;
	
}

void solve(){
	
	possible = false;
	v.assign(n , 0);
	plu.assign(n ,0);
	minu.assign(n, 0);
	
	for(int i =0 ; i < n; i++)cin >> v[i];
	
	
	for(int i =0 ; i < 42 ; i++){
		for(int j =0 ; j < max_n ;j++){
			dp[i][j] = -1;
		}
	}
	
	calc(0 , 0);
	calc(0 , 0);
	
	if(possible){
		for(int i =0 ; i < n; i++){
			if(plu[i] == 1 && minu[i] == 1)
				cout<<"?";
			else if(plu[i] == 1)
				cout<<"+";
			else
				cout<<"-";
		}
		cout<<"\n";
	}
	else{
		cout<<"*\n";
	}	
	
}

signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	cin >> n >> target;
	
	while(n != 0 || target != 0){
		solve();
		cin >> n >> target;
	}
	
	
	return 0;
}
