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
	fast();
	int n;
	cin>>n;
	double temp=(double)log2(n);
	int noOfBits;
	noOfBits=(int)temp+1;
	int ans=0;
	n++;
	for(int i=0;i<noOfBits;i++)
	{
		int noOfPerfectPartitions=(n/(ll)pow(2,i+1));
		ans+=noOfPerfectPartitions*(ll)pow(2,i);
		int rem=n%((ll)pow(2,i+1));
		if(rem>(ll)pow(2,i))
		ans+=rem-(ll)pow(2,i);
	}
	cout<<ans<<"\n";
}
 
