class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int val = max(arr[0] , arr[1]);
        int cnt = 0;
        for(int i = 2 ; i< n; i++){
            // cout<<cnt;
            if(cnt == k - 1){
                break;
            }
            if(val > arr[i]){
                cnt += 1;
            }
            else{
                cnt = 0;
                val = arr[i];
            }
            
        }
        return val;
        
    }
};
