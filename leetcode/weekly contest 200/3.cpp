class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        bool ok = true;
        
        int rows = grid.size();
        int cols = rows;
        
        vector<int> info(rows);
        
        for(int i =0 ; i < rows; i++){
            int cnt = 0;
            for(int j = cols - 1; j>=0 ;j--){
                if(grid[i][j] == 1){
                    break;
                }
                cnt += 1;
            }
            info[i] = cnt;
        }
        
        int req = rows - 1;
        int ans = 0;
        for(int i  = 0; i < rows ; i++){
            bool found = false;
            for(int j = i ; j < rows ; j++){
                if(info[j] >= req){
                    
                    
                    for(int k = j ; k > i; k--){
                        swap(info[k-1] , info[k]);
                    }
                    
                    ans += j - i;
                    found = true;
                    break;
                }
                
                
            }
            
            if(!found){
                ok = false;
            }
            req -= 1;
        }
        
        if(ok)
            return ans;
        else
            return -1;
        
    }
};
