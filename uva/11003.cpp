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
 

int money,n;
const int inf = -1e6;
vector<int> price;
vector<int> value;	
	
signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	while(scanf("%lld %lld" , &money ,&n) != EOF){
		
		money += 200;
		
		price.resize(n);
		value.resize(n);
		
		for(int i =0 ; i< n; i++){
			cin >> price[i] >> value[i];
		}
		
		vector<int> dp(money+1, inf);
		dp[0] = 0;
		for(int i =0 ; i< n ; i++){
			
			vector<int> new_dp = dp;
			
			for(int j =0 ; j < money+1; j++){
				if(dp[j] != inf && j+price[i] <= money){
					new_dp[j+price[i]] = max(new_dp[j+price[i]] , dp[j] + value[i] );
				}
			}
			
			dp = new_dp;
		}
		
		int ans =0 ;
		
		for(int i =0 ; i< money+1; i++){
			if(ans < dp[i] && i < 2001 && i > money - 200)
				continue;
			ans = max(dp[i] , ans);
		}
		
		cout<<ans<<"\n";
		//debug(ans);
		
	}	
	
	
	
	return 0;
}
