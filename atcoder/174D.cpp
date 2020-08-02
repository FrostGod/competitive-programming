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
//#define eps (double)1e-9
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

//const int nax = 1e5 + 2;
const double eps = -1e3;
int n,k;
vector<double> v;
bool check(double val){
	//debug(val);
	int cnt = 0;
	for(int i =0 ; i < n ;i++){
		if(v[i] > val){
			int temp = 0;
			
			temp += v[i]/val;
			if(temp*v[i] < val){
				temp += 1;
			}
			cnt += temp;	
		}
		
	}
	
	if(cnt > k){
		return false;
	}
	else
		return true;
	
}

signed main() {    
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    v.assign(n , 0);
    for(int i =0 ; i < n; i++){
		cin >> v[i];
	}
    
    int ma = *max_element(all(v));
    //int mi = *min_element(all(v));
    
    double ans = ma;
    
    double l = 0 , r = ma;
    while(abs(l - r) > 0.000001){
		//debug(l , r);
		
		double mid = l + (r - l)/2.00000;
		
		bool val = check(mid);
		
		if(val){
			ans = mid;
			
			r = mid;
		}
		else{
			l = mid;
		}
		
	}
    
    //debug(ans);
    double val = ceil(ans);
    double val2 = floor(ans);
    
    if(ans - l <= r - ans){
		cout<<(int)val2;
	}
	else{
		cout<<(int)val;
	}
    
    
    return 0;
}
