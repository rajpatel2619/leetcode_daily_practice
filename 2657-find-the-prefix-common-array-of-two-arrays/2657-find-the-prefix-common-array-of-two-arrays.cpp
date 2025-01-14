class Solution {
public:
    int count(int n, vector<int>&a, vector<int>&b){
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i]==b[j])
                    c++;
            }
        }
        return c;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i] = count(i+1, A, B);
        }
        return res;
    }
};