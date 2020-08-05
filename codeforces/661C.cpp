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
    
    int t;
    cin >> t;
    while(t--){
		int n;
		cin >> n;
		
		vector<int> v(n);
		
		map<int,int> m;
		for(int i =0 ; i< n; i++){
			cin >> v[i];
			m[v[i]] += 1;
		}
		
		int ans = 0;
		
		sort(all(v));
		
		for(int w = 1; w <= 2*n; w++){
			int val = w;
			
			map<int,int> temp = m;
			
			int teams = 0;
			
			for(int i =0 ; i < n; i++){
				if(temp[v[i]] >= 1){
					int req = val - v[i];
					if(req == v[i]){
						if(temp[v[i]] >= 2){
							teams += 1;
							temp[req] -= 2;
						}
						
					}
					else if(req >= 1){
						if(temp[req] >= 1){
							teams += 1;
							temp[req] -= 1;
							temp[v[i]] -= 1;
						}
					}
					
				}
				ans = max(ans , teams);
				
			}
			
		}
		
		cout<<ans<<"\n";
	}
   
	 
    return 0;
}
