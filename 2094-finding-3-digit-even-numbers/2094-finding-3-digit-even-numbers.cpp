class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> f;
        for(auto e:digits)
            f[e]++;
        vector<int> res;
        for(int i=100;i<1000;i++){
            if(i&1) continue;
            int t = i;
            vector<int> arr(10,0);
            while(t){
                arr[t%10]++;
                t/=10;
            }
            bool ok  = true;
            for(int i=0;i<10;i++){
                if(f[i]<arr[i]){
                    ok = false;
                    break;
                }
            }
            if(ok)
                res.push_back(i);
        }
        return res;
    }
};