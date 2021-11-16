#include <iostream> 
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>  
#include <math.h>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cstring>
#include <cassert>


#define pb push_back
#define int long long
#define ll long long
#define x first
#define y second
#define all(x) x.begin(),x.end()

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

const int inf = (ll)1e18 + 5ll;
const int mod =   (int)998244353;


int power(int a, int b){
	int ans =1ll;
	while(b > 0){
		if(b%2ll == 1ll){
			ans = (ans * a)%mod;
		}

		a = (a * a)%mod;
		b /= 2ll;
	}
	return ans;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}


void solve(){
	string s;
	cin >> s;

	set<char> vowel;
	vowel.insert('A');
	vowel.insert('E');
	vowel.insert('I');
	vowel.insert('O');
	vowel.insert('U');

	int n = s.size();
	int ans = inf;

	for(int i =0; i<26; i++){
		char c = 'A' + i;
		int cost = 0;
		if(vowel.find(c) != vowel.end()){
			for(int i=0; i<n; i++){
				if(s[i] == c)
					continue;

				if(vowel.find(s[i]) == vowel.end()){
					cost += 1;
				}
				else{
					cost += 2;
				}

			}
		}
		else{
			for(int i=0; i<n; i++){
				if(s[i] == c)
					continue;

				if(vowel.find(s[i]) != vowel.end()){
					cost += 1;
				}
				else{
					cost += 2;
				}

			}
		}
		ans = min(ans, cost);
	}
	cout << ans << "\n";

}

signed main(){

	freopen("FB/consistency_chapter_1_input.txt", "r", stdin);
	freopen("FB/A1.txt", "w", stdout);

	int t;
	cin >> t;
	int cnt = 1;
	while(t--){
		cout << "Case #"<<cnt<<": ";
		solve();
		cnt += 1;
	}
	
	return 0;
}
