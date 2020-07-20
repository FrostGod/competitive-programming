#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<cmath>
#include<cstring>
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


const int mod  = (int)1e9 + 7;


int c[2][2];
int d[1][2];

void multiply2(int a[2][2] , int b[2][2]){
	
	for(int i =0 ; i < 2; i++)
		for(int j =0 ; j < 2; j++)	
			c[i][j] = 0;
	
	for(int i =0 ; i < 2 ; i++){
		for(int j =0 ; j < 2 ; j++){
			for(int k = 0;k < 2; k++){
				c[i][j]  = (c[i][j] + (a[i][k]*b[k][j])%mod)%mod;
			}
		}
	}
}


void multiply1(int a[1][2], int b[2][2]){
	d[0][1] = 0;
	d[0][0] = 0;
	for(int i =0 ; i <1 ; i++ ){
		for(int j = 0 ; j < 2; j++){
			for(int k = 0; k < 2; k++){
				d[i][j] = (d[i][j] + (a[i][k]*b[k][j])%mod ) %mod;
			}
		}
	}	
	
	 
}

signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	if(n == 0){
		cout << 0;
		return 0;
	}
	
	n -= 1;
	
	int b[2][2] = { {0,1} , {1,1} };
	int a[1][2] = {0 , 1};
	
	while(n >= 1){
		if(n%2 == 1){
			multiply1(a , b);
			a[0][1] = d[0][1];
			a[0][0] = d[0][0];
			
		}
		multiply2(b ,b);
		
		for(int i =0 ; i< 2; i++)
			for(int j =0 ; j < 2; j++)
				b[i][j] = c[i][j];
		
		n /= 2;
	}
	
	cout<<a[0][1];
	
	
	return 0;
}
