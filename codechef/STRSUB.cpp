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
 
 
int n,k,q;
string s;

void solve(){
	cin >> n >> k >> q;
	cin >> s;
	
	vector<int> zero(n+1,  0);
	vector<int> one(n+1, 0);
	
	
	for(int i = 0 ;  i <n ; i++){
		if(s[i] == '0'){
			zero[i+1] += 1;
		}
		else
			one[i+1] += 1;
	}
	
	for(int i =1 ; i<= n ; i++){
		zero[i] += zero[i-1];
		one[i] += one[i-1];
	}
	
	vector<int> large(n+1) , dp(n+1, 0);
	
	for(int i = 1; i <=n ; i++){
		int val = zero[i] + k;
		if(s[i-1] != '0'){
			val += 1;
		}
		int val1 = 0;
		auto it = lower_bound(all(zero) , val);
		if(it == zero.end()){
			val1 = n;
		}
		else{
			int pos = (int)(it - zero.begin()) -1 ;
			//debug(pos);
			val1 = pos;
		}
		//debug(val1);
		
		int val2 = 0;
		
		val = one[i] + k;
		if(s[i-1] != '1'){
			val += 1;
		}
		//int val1 = 0;
		it = lower_bound(all(one) , val);
		if(it == one.end()){
			val2 = n;
		}
		else{
			int pos = (int)(it - one.begin()) -1 ;
			//debug(pos);
			val2 = pos;
		}
		
		val = min(val1, val2);
		//debug(val);
		large[i] = val;
		val = (val - i ) + 1;
		dp[i] = val;
		
	}
	
	//debug(large);
	for(int i =1 ; i <= n; i++){
		dp[i] += dp[i-1];
	}
	
	
	while(q--){
		int l,r;
		cin >> l >> r;
		int ans = 0;
		int lb,rb,mb;
		lb = l ,rb = r;
		int pos = -1;
		while(lb <= rb){
			mb = lb + (rb - lb)/2;
			if(large[mb] > r){
				rb = mb -1;
			}
			else{
				pos = mb;
				lb = mb + 1;
			}
			
		}
		//debug(pos);
		if(pos != -1){
			ans = dp[pos] - dp[l-1];
			//debug(ans);
			int val = (r - pos);
			ans += (val*(val+1))/2;
			
		}
		else{
			int val = (r-l+1);
			ans = (val*(val+1))/2;
		}
		cout<<ans<<"\n";
	}
	
		
}
	
signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	
	
	
	
	return 0;
}
