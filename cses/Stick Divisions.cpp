//@author yash2040
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int32_t main()
{
	priority_queue<int,vector<int>,greater<int>> pq;
	int x,n;
	cin>>x>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		pq.push(arr[i]);
	}
	int ans=0;
	while(pq.size()!=1)
	{
		int fi=pq.top();
		pq.pop();
		int si=pq.top();
		pq.pop();
		
		ans+=(fi+si);
		pq.push(fi+si);
	}
	cout<<ans<<"\n";
	
}







