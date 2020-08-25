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



signed main() {    
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	 
	int n , tot;
	cin >> n >> tot;
	
	
	int pow[21];
	
	pow[0] = 1;
	
	for(int i = 1 ; i <= 20; i++){
		pow[i] = pow[i-1]*2;
	}
	
	
	vector<int> v(n) , list1 , list2;
	
	for(int i =0 ; i <n ;i++)
		cin >> v[i];
	
	for(int i =0 ; i < (n+1)/2 ; i++){
		list1.pb(v[i]);
	}
	
	for(int i =(n+1)/2; i < n; i++){
		list2.pb(v[i]);
	}
	
	int mid  = (n+1)/2;
	
	vector<int> m;
	
	//debug(mid);
	
	for(int i =1 ; i < (1<<mid) ; i++){
		int sum = 0;
		for(int j =0 ; j < mid; j++){
		
			int val = pow[j];
			if((i&val) != 0){
				sum += list1[j];
			}
			if(sum > tot){
				break;
			}
			
		}
		if(sum <= tot){
			m.pb(sum);
		}
	}
	
	//debug(m);
	
	sort(all(m));
	
	auto it = lower_bound(all(m) , tot);
	int num =0 ;
	if(it != m.end()){
		num = (int)(m.end() - it);
	}
	
	int ans = num;
	//debug(ans);
	
	//debug(ans);
	
	int rem = n - mid;
	//debug(rem);
	
	for(int i = 1; i < (1<< rem); i++){
		int sum = 0;
		for(int j =0 ; j < rem; j++){
		
			int val = pow[j];
			if((i&val) != 0){
				sum += list2[j];
			}
			if(sum > tot){
				break;
			}
			
		}
		
		if(tot == sum)
			ans += 1;
		else if(tot > sum){
			int req = tot - sum;
			
			auto ip = lower_bound(all(m) , req);
			num = (int)(upper_bound(all(m) , req) - ip);
			ans += num;
			
			
		}
		
	}
	
	cout<<ans;
	
	 
	return 0;
}
