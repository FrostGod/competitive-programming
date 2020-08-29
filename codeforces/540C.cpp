#include <bits/stdc++.h> 
#include<cmath>
#include<string>
#define pb push_back
#define x first
#define y second
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
 
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
	
	int n;
	cin >> n;
	
	map<int,int> m;
	set<int> s;
	for(int i =0 ; i < n*n; i++){
		int temp;
		cin >> temp;
		m[temp] += 1;
		s.insert(temp);
	}
	
	//debug(m);
	
	int ele = -1;
	int cnt = 0;
	bool ok = true;
	
	set<int> middle;
	
	for(auto it : m){
		if(it.y%4 != 0){
			cnt += 1;
			if(it.y > 1){
				middle.insert(it.x);
			}
			if(it.y%2 == 1){
				ele = it.x;
			}
		}
	}
	
	if(n%2 == 0 && cnt != 0){
		ok = false;
	}
	if(!ok){
		cout<<"NO";
		return 0;
	}
	
	int mat[n][n];
	
	bool vis[n][n];
	
	for(int i= 0; i < n; i++){
		for(int j =0; j < n; j++){
			mat[i][j] = 0;
			vis[i][j] = false;
		}
	}
	
	//debug(middle);
	
	bool poss = true;
	//debug(ele);
	if(n%2 == 1){
		if(ele == -1){
			poss = false;
		}
		//debug("hi");
		mat[n/2][n/2] = ele;
		vis[n/2][n/2] = true;
		m[ele] -= 1;
		if(m[ele] == 0){
			s.erase(ele);
			middle.erase(ele);
		}
		if(m[ele]%4 == 0){
			middle.erase(ele);
		}
		
		for(int i = 0 ; i< n /2 ;i++){
			int val =0;
			if(!middle.empty()){
				val = *middle.begin();
			}
			else{
				val = *s.begin();
			}
			//debug(val);
			vis[n/2][i] = true;
			vis[n/2][n - (i+1)] = true;
			mat[n/2][i] = val;
			mat[n/2][n - (i+1)] = val;
			if(m[val] < 2){
				poss= false;
				break;
			}
			m[val] -= 2;
			if(m[val] == 0){
				s.erase(val);
				middle.erase(val);
			}
			if(m[val] %4 == 0){
				middle.erase(val);
			}
		}
		
		for(int i = 0 ; i< n /2 ;i++){
			int val =0;
			if(!middle.empty()){
				val = *middle.begin();
			}
			else{
				val = *s.begin();
			}
			vis[i][n/2] = true;
			vis[n - (i+1)][n/2] = true;
			mat[i][n/2] = val;
			mat[n - (i+1)][n/2] = val;
			if(m[val] < 2){
				poss= false;
				break;
			}
			m[val] -= 2;
			if(m[val] == 0){
				s.erase(val);
				middle.erase(val);
			}
			if(m[val] % 4 == 0){
				middle.erase(val);
			}
		}
		
		
	}
	
	//debug(middle);
	if(!middle.empty()){
		ok = false;
	}
	
	if(!poss){
		//debug("hi");
		cout<<"NO";
		return 0;
	}
	
	//debug(middle);
	
	for(int i =0 ; i < n; i++){
		for(int j =0 ; j < n; j++){
			if(vis[i][j] == false){
				
				//set<
				vis[i][j] = true;
				vis[n-(i+1)][j] = true;
				vis[i][n-(j+1)] = true;
				vis[n-(i+1)][n-(j+1)] = true;
				int val = *s.begin();
				mat[i][j] = val;
				mat[n-(i+1)][j] = val;
				mat[i][n-(j+1)] = val;
				mat[n-(i+1)][n-(j+1)] = val;
				
				if(m[val] < 4){
					poss= false;
					break;
				}
				
				m[val] -= 4;
				if(m[val] == 0){
					s.erase(val);
				}
 			}
		}
	}
	
	if(!poss){
		cout<<"NO";
		return 0;
	}
	
	cout<<"YES\n";
	for(int i =0 ; i < n; i++){
		for(int j =0 ; j < n; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	 
	return 0;
}
