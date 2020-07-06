#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long 
#include <set>
#include <map>


#define first x
#define second y
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
 
 
 
//bool comp()


 
signed main() {
	
	int n,k;
	cin >> n >> k;
	//vector<pair<int,pair<int,int>> v(n);
	
	int alice = 0, bob = 0;
	
	
	vector<int> only_alice , only_bob;
	
	vector<int> fin;
	
	for(int i =0 ; i < n ;i++){
		int t,a,b;
		cin >> t >> a >> b;
		if(a == 1){
			alice += 1;
		}
		if(b == 1){
			bob += 1;
		}
		
		if((a^b )== 1){
			if(a == 1){
				only_alice.pb(t);
			}
			else{
				only_bob.pb(t);
			}
		}
		//v[i] = {t , {a,b}};
		
		if(a == 1 && b == 1){
			fin.pb(t);
		}
		
		
	}
	
	if(alice < k || bob < k){
		cout<<"-1";
		return 0;
	}
	
	//sort(all(v) , comp);
	
	sort(all(only_alice));
	sort(all(only_bob));
	
	for(int i = 0; i < min((int)only_alice.size() , (int)only_bob.size()); i++){
		int val = only_alice[i] + only_bob[i];
		fin.pb(val);
	}
	
	sort(all(fin));
	
	int ans =0 ;
	for(int i =0 ; i < k ;i++){
		ans += fin[i];
	}
	
	cout<<ans;
	
	return 0;
}
