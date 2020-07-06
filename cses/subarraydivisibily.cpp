#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef vector<int> vi;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
int maxi = 1e9;
 
signed main() {
    int n;
    cin >> n;
    
    maxi = maxi*n;
    
    vector<int> v(n);
    int ans = 0;
    map<int,int> m;	
    for(int i = 0 ; i <n ; i++){
		cin >> v[i];
		//if(v[i] % n == 0){
			//ans++;
		//}
	}
	int sum = 0;
	m[0] = 1;
	for(int i=0 ; i<n; i++){
		sum = (sum + v[i]+ maxi)%n;
		//cout<<sum<<" ";
		ans += m[sum];
		m[sum] += 1;
	}
	cout<<ans;
	
}
