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
 
 
 



int n,q;


signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	cin >> n >> q;
	vector<pair<int, pair<int,int>>> v(n);
	
	for(int i =0 ; i < n ; i++){
		cin >> v[i].y.x >> v[i].y.y >> v[i].x;
	}
	 
	set<int> s;
	
	vector<int> ans(q, -1);
	
	map<int,int> m;
	
	
	for(int i =0 ; i < q; i++){
		int temp;
		cin >> temp;
		s.insert(temp);
		m[temp] = i;
	}
	 
	 sort(all(v));
	 
	 
	 for(int i =0 ; i < n;i++){
		 int left = v[i].y.x - v[i].x;
		 int right = v[i].y.y - 1 - v[i].x;
		 
		 //debug(left , right , v[i].x);
		 
		 while(true){
			 auto it = s.lower_bound(left);
			 
			 if(it == s.end()){
				 break;
			 }
			 
			 int val = *it;
			 if(val > right){
				break;
			 }
			s.erase(val);
			int pos = m[val];
			ans[pos] = v[i].x;
			 
		 }
	 }
	
	for(int i =0; i < q; i++){
		cout<<ans[i]<<"\n";
	}
	
	
	return 0;
}
