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
 

int n ,m ;
vector<int> v;
int ma = -5000;
int mi = 5000;
int tt =0 ;
bool vis[103][5002][51];

void calc(int idx ,  int sum ,int select){
	
	
	if(select > n)
		return;
	
	if(vis[idx][sum+2500][select] != false)
		return ;
	
	if(idx == n+m){
		
		if(select < n){
			vis[idx][sum+2500][select] = true;
			return ;
		}
		//debug(sum);
		int val = tt-sum;
		//debug(val , sum);
		val = val*sum;
		mi = min(val , mi);
		ma = max(val , ma);
		vis[idx][sum+2500][select] = true;
		return ;
	}
	
	
	
	
	calc(idx+1 , sum ,select);
	calc(idx+1,sum+v[idx],select+1);
	
	vis[idx][sum+2500][select] = true;
	
	
}

signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	while(cin >> n >> m){
		
		
		tt =0;	
		v.assign(n+m ,0);
		for(int i =0 ; i < n +m ;i++)
			cin >> v[i],tt+= v[i];
		
		for(int i= 0; i < 103; i++){
			for(int j =0 ; j <= 5000; j++){
				for(int k =0 ; k <= 50 ;k++)
					vis[i][j][k] = false;
			}
		}
		mi = 5000;
	    ma = -5000;
		calc(0 , 0 ,0);
		debug(mi , ma);
		cout<<ma <<" " <<mi<<"\n";
		
	}
	
	
	
	
	
	return 0;
}
