class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>f(n+1,0);
        int c = 0;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            f[A[i]]++;
            if(f[A[i]]==2)
                c++;
            f[B[i]]++;
            if(f[B[i]]==2)
                c++;
            res[i] = c;
        }
        return res;
    }
};