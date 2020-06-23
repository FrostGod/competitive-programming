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
#define no cout<<"NO"<<"\n"
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
const int max_n = 8;
char mat[max_n][max_n];


	
signed main(){
	fast;
	
	for(int i =0 ; i < max_n ; i ++ ){
		for(int j = 0 ; j < max_n ; j++){
			cin >> mat[i][j];
		}
	}
	
	
	int ans = 0;
	
	vector<int> v = {0,1,2,3,4,5,6,7};
	int cnt =1;
	do{
		//deb(cnt);
		char board[max_n][max_n];
		memcpy(board , mat, sizeof(board));
		bool ok = true;
		for(int i = 0 ; i < max_n ; i++){
			if(mat[i][v[i]] == '*'){
				ok = false;
			}
			board[i][v[i]] = 'q';
		}
		
		if(!ok)
			continue;
			
		for(int i =1 ; i < max_n; i++){
			int j = v[i];
			if(j > 0){
				for(int k = i-1,q = j-1; q>=0&&k>=0 ;q--,k--){
					if(board[k][q] == 'q'){
						ok = false;
						//debug(i,v[i],k ,q);
						break;
					}
				}
			}
			if(j < max_n){
				//j++;
				for(int k = i -1,q = j+1; q < max_n&&k >= 0 ; q++,k--){
					if(board[k][q] == 'q'){
						ok = false;
						//debug(i,v[i],k ,q);
						break;
					}
				}
				
			}
			//cnt++;
		}
		if(ok){
			ans++;
			//debug(v);
		}
		cnt++;
		
	}while(next_permutation(all(v)));
	
	cout<<ans;
	
	return 0;
}

	

