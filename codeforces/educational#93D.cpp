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

 
vector<int> red, blue ,green;
int r,b,g;

int dp[201][201][201];

int calc(int idx1 , int idx2 , int idx3){
	if(idx1 == r && idx2 == b){
		return 0;
	}
	if(idx1 == r && idx3 == g){
		return 0;
	}
	if(idx3 == g && idx2 == b){
		return 0;
	}
	
	if(dp[idx1][idx2][idx3] != -1){
		return dp[idx1][idx2][idx3];
	}
	
	int ans = 0;
	
	if(idx1 != r && idx2 != b){
		ans = calc(idx1+1 , idx2 + 1 , idx3) + red[idx1]*blue[idx2];
	}
	if(idx1 != r && idx3 != g){
		ans = max(calc(idx1 + 1, idx2 , idx3 +1) + red[idx1]*green[idx3] , ans);
	}
	if(idx2 != b && idx3 != g){
		ans = max(ans , calc(idx1 , idx2 + 1, idx3 + 1) + blue[idx2]*green[idx3]);
	}
	
	dp[idx1][idx2][idx3] = ans;
	return ans;
	
}

signed main() {    
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> r >> b >> g;
    
    for(int i =0 ; i < r ; i++){
		int temp;
		cin >> temp;
		red.pb(temp);
	}
	
	
    for(int i =0 ; i < b ; i++){
		int temp;
		cin >> temp;
		blue.pb(temp);
	}
	
	for(int i =0 ; i < g ; i++){
		int temp;
		cin >> temp;
		green.pb(temp);
	}
    
    sort(all(red));
    sort(all(green));
    sort(all(blue));
    
    reverse(all(red));
    reverse(all(blue));
    reverse(all(green));
    
    
    for(int i= 0 ; i < 201 ;i++){
		for(int j = 0 ;j < 201 ;j++){
			for(int k =0 ; k < 201 ;k++){
				dp[i][j][k] = -1;
			}
		}
	}
    
    int ans = calc(0 , 0 , 0);
    
    
   cout<<ans;
   
   return 0;
}
