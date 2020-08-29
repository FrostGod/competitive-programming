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


vector<int> v;
int n,m;

bool check(int days){
	int now = 0 ;
	int pages = 0;
	int cnt = 0;
	for(int i =0 ; i <n ;i++){
		pages += max(v[i] - cnt , 0ll);
		//debug(pages,cnt);
		now += 1;
		if(now == days){
			cnt += 1;
			now = 0;
		}
	}
	
	//if(days == 1){
		//debug(pages);
	//}
	
	if(pages >= m){
		return true;
	}
	
	return false;
}

signed main() {    
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> n>>m;	
	
	v.assign(n , 0);
	
	for(int i =0 ; i < n ; i++){
		cin >> v[i];
	}
	
	sort(all(v));
	reverse(all(v));
	int l = 1 , r = n;
	
	int ans = -1;
	while(l <= r){
		int mid = l + (r- l)/2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout<<ans;
	
	 
	return 0;
}
