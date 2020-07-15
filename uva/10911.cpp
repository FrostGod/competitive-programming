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
//#define no cout<<"NO"<<"\n"
#define INF (int)1e5+5
#define nax (int)1e6+3
#define eps (double)1e-9
#define all(x) x.begin(),x.end()
#define MAX_N (int)1e6+2
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
 

int n;
double dis[16][16];
const int inf = 1e9+7;
pair<int,int> points[16];
int complete;

double dp[1<<17];


double calc(int mask){
	
	if(dp[mask] != -1){
		return dp[mask];
	}
	
	if(mask == complete){
		return 0;
	}
	
	double ans = inf;
	
	int pos = 0;
	for(int i = 0; i < 2*n ;i++){
		if((mask&(1<<i)) == 0){
			pos = i;
			break;
		}
	}
	
	mask = mask | (1<<pos) ;
	for(int i =pos+1; i<2*n ;i++){
		if((mask & (1<<i)) == 0){
			int new_mask = mask | (1<<i);
			double val = dis[pos][i] + calc(new_mask);
			ans = min(ans , val);
		}
	}
	
	dp[mask] = -1;
	
	return ans;
	
}


signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	//int n;
	
	cin >> n;
	int cnt = 1;
	while(n != 0){
		
		string name;
		int val_x , val_y;
		
		for(int i =0 ; i < 2*n; i++){
			cin >> name >> val_x >> val_y;
			points[i].x = val_x ;
			points[i].y = val_y;
		}
		
		for(int i =0 ; i < 2*n; i++){
			for(int j = 0; j < 2*n ; j++){
				dis[i][j] = (points[i].x - points[j].x)*(points[i].x - points[j].x);
				dis[i][j] += (points[i].y - points[j].y)*(points[i].y - points[j].y);
				dis[i][j] = sqrt(dis[i][j]);
			}
		}
		
		complete = (1<<(2*n)) -1;
		//debug(complete);
		
		//int val = 1<<17;
		//edebug(val);
		
		for(int i =0 ; i <1<<17; i++){
			dp[i] = -1;
		}
		
		
		int mask = 0;
		double ans = calc(mask);
		cout<<"Case "<<cnt<<": "<<fixed<<setprecision(2)<<ans<<"\n";
		cnt += 1;
		
		cin >> n;
		if(n == 0)
			break;
	}
	
	return 0;
}
