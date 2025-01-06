class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int rones = 0, lones = 0;
        long long rsum = 0;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                rsum+=i;
                rones++;
            }
        }
        vector<int> res(n);
        long long lsum = 0;
        for(int i=0;i<n;i++){
            int m = lsum+rsum;
            res[i] = m;
            if(boxes[i]=='1'){
                rones--;
                lones++;
            }
            rsum-=rones;
            lsum+=lones;
        }
        return res;
    }
};