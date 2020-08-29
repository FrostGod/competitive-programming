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




signed main() {    
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	
	int odd_sum = 0, even_sum =0;
	
	vector<int> sum(n, 0);
	
	for(int i =0 ;i < n; i++){
		cin >> v[i];
		if(i%2){
			even_sum += v[i];
			sum[i] = even_sum;
		}
		else{
			odd_sum += v[i];
			sum[i] = odd_sum;
		}
	}
	
	
	int ans =0;
	for(int i =0 ;i  < n; i++){
		int v1 =0 , v2 = 0;
		if(i%2 == 1){
			v1 = sum[i-1] + even_sum - sum[i];
			v2 = sum[i] - v[i] + odd_sum - sum[i-1];
		}
		else{
			v1 = i >= 2 ? sum[i-2] : 0;
			v1 += even_sum - (i > 1 ? sum[i-1] : 0);
			v2 = i > 1? sum[i-1] : 0;
			v2 += odd_sum - sum[i];
			
		}
		if(v1 == v2){
			//debug(i+1);
			ans += 1;
		}
	}
	cout<<ans;
	 
	return 0;
}
