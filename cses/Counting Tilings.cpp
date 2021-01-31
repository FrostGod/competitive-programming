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
void generateNextMask(int currentMask,int mask,int n,int i,vector<int>& nextMasks)
{
	if(i==n)
	{
		nextMasks.pb(mask);
		return;
	}
	if(((1<<i) & (currentMask)) !=0)
	generateNextMask(currentMask,mask,n,i+1,nextMasks);
	
	if(((1<<i)&(currentMask))==0 and i!=n-1)
	{
		if(((1<<(i+1))&(currentMask))==0)
		generateNextMask(currentMask,mask,n,i+2,nextMasks);
		generateNextMask(currentMask,mask+(1<<i),n,i+1,nextMasks);
	}
	if(((1<<i)&(currentMask))==0 and i==n-1)
	{
		generateNextMask(currentMask,mask+(1<<i),n,i+1,nextMasks);
	}
	
}
vector<vector<int>> dp((1<<11),vector<int>(1002,-1));
int countTilings(int col,int mask,int n,int m)
{
	if(col==m)
	{
		if(mask==0)
		return 1;
		return 0;
	}
	if(dp[mask][col]!=-1)
	return dp[mask][col];
	
	vector<int> nextMasks;
	generateNextMask(mask,0,n,0,nextMasks);
	
	
	int ans=0;
	for(auto it:nextMasks)
	{
		ans=(ans%mod+countTilings(col+1,it,n,m)%mod)%mod;
	}
	return dp[mask][col]=ans;
}
int32_t main()
{
	fast();
	int n,m;
	cin>>n>>m;
	
	cout<<countTilings(0,0,n,m);
}







