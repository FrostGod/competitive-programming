using ll =long long int;
const ll mod = (ll)1e9+7;
class Solution {
public:
    long maxSum(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        
        vector<ll> nums1(n1), nums2(n2);
        
        for(int i =0 ; i < n1 ; i++)nums1[i] = v1[i];
        for(int i =0 ; i < n2 ; i++)nums2[i] = v2[i];
        
        set<ll> s ,one;
        map<ll,int> m1 , m2;
        
        vector<ll> pre1(n1 , (ll)0) , pre2(n2, (ll)0);
        
        for(int i = 0; i < n1; i++){
            one.insert(nums1[i]);
            pre1[i] =  nums1[i] + (i > 0 ? pre1[i-1] : (ll)0);
            m1[nums1[i]] = i;
        }
        
        for(int i = 0 ;i  < n2 ; i++){
            if(one.find(nums2[i]) != one.end()){
                s.insert(nums2[i]);
            }
            pre2[i] =  nums2[i] + (i > 0 ? pre2[i-1] : (ll)0);
            m2[nums2[i]] = i;
        }
        
        
        ll ans = 0;
        int last1 = 0 , last2 = 0;
        for(auto it: s){
            int pos1 = m1[it];
            int pos2 = m2[it];
            ll val1 = pre1[pos1] - (last1 > 0 ? pre1[last1-1] : (ll)0);
            ll val2 = pre2[pos2] - (last2 > 0 ? pre2[last2 - 1]: (ll)0);
            ans += max(val1 , val2);
            last1 = pos1 +1;
            last2 = pos2 + 1;
        }
        
        ll val1 = pre1[n1-1] - (last1 > 0 ? pre1[last1-1] : (ll)0);
        ll val2 = pre2[n2-1] - (last2 > 0 ? pre2[last2 - 1]: (ll)0);
        ans = (ans +  max(val1 , val2));
        
        return (long)(ans%mod);
        
        
    }
};
