class Solution {
public:
    vector<int> minOperations(string str) {
        int n = str.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int cnt = 0;
            //prev
            for(int j=i-1;j>=0;j--){
                if(str[j]=='1'){
                    cnt+=abs(i-j);
                }
            }
            //after
            for(int j=i+1;j<n;j++){
                if(str[j]=='1'){
                    cnt+=abs(j-i);
                }
            }
            res[i] = cnt;
        }
        return res;
    }
};