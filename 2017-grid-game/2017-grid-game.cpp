class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
       int n = grid[0].size();
       vector<long long> sufa(n, grid[0][n-1]), sufb(n, grid[1][n-1]);
       for(int i=n-2;i>=0;i--){
            sufa[i] = grid[0][i]+sufa[i+1];
            sufb[i] = grid[1][i]+sufb[i+1];
       } 
       int ind = n-1;
       for(int i=n-2;i>=0;i--){
            if(sufb[i]>=sufa[i+1]){
                ind = i;
            }
       }
    //    int r = 0;
       grid[1][n-1] = grid[0][0] = 0;
    //    for(int i=0;i<n-2;i++){
    //         if(!r){
    //             if(sufa[i+1]>sufb[i]){
    //                 grid[0][i+1] = -1;
    //             }else{
    //                 r=1;
    //                 grid[r][i] = -1;
    //             }
    //         }else{
    //             grid[1][i] = -1;
    //         }
    //    }
    //    long long sum = 0;
    //    for(int i=0;i<n;i++){

    //    }
        long long suma = 0, sumb=0;
        for(int i=0;i<ind;i++)
            suma+=grid[1][i];
        for(int i=ind+1;i<n;i++)
            sumb+=grid[0][i];
        return max(suma, sumb);
    }
};