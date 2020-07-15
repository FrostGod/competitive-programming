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
 

const int inf = 1e6;
int n;
vector<int> boxes;
vector<int> values;

int cache[3002][3002];
	
	
int calc(int weight_now , int idx){
	
	//debug(weight_now,idx);
	
		
	if(idx == 0)
		return 0;
	
	
	if(cache[weight_now][idx] != -1){
		return cache[weight_now][idx];
	}
		
	int max_boxes = -inf;
	
	if(weight_now <= values[idx]){
		int val = calc(weight_now+boxes[idx] , idx-1)+1;
		max_boxes = val;
	}
	int temp = calc(weight_now , idx-1);
	max_boxes = max(temp , max_boxes);

	cache[weight_now][idx] = max_boxes;
	
	return max_boxes;
}
	
	
signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	cin >> n;
	while(n !=0 ){
		boxes.assign(n+1, 0 );
		values.assign(n+1 , 0);
		
		values[0] = inf;
		for(int i =0 ; i < 3001; i++){
			for(int j = 0;  j< 3001; j++){
				cache[i][j] = -1;
			}
		}
		
		
		for(int i =1 ; i <= n ; i++){
			cin >> boxes[i] >> values[i];
		}
		
		
		
		
		int ans =  calc(0 , n);
		cout<<ans<<"\n";
		
		cin >> n;
	}
	return 0;
}
