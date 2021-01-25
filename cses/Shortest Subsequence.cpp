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
	string s;
	cin>>s;
	set<char> se;
	string ans="";
	for(int i=0;i<s.length();i++)
	{
		se.insert(s[i]);
		if(se.size()==4)
		{
			ans+=s[i];
			se.clear();
		}
	}
	for(auto it:"ACGT")
	{
		if(se.find(it)==se.end())
		{
			ans+=it;
			break;
		}
	}
	cout<<ans<<"\n";
}
