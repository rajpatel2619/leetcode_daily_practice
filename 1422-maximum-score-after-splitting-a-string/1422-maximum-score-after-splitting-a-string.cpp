class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> pref(n), suf(n);
        pref[0] = (s[0]=='0')?1:0;
        suf[n-1] = (s[n-1]=='1')?1:0;
        for(int i=1;i<n;i++){
            pref[i] = (s[i]=='0')? pref[i-1]+1:pref[i-1];
        } 
        for(int i=n-2;i>=0;i--){
            suf[i] = (s[i]=='1')? suf[i+1]+1:suf[i+1];
        } 
        int maxi = max(pref[n-1]-1, suf[0]-1);
        for(int i=0;i<n-1;i++){
            if(s[i]=='1') continue;
            // cout<<pref[i]<<" "<<suf[i]<<endl;
            maxi = max(maxi, abs(pref[i]+suf[i]));
        }
        return maxi;
    }
};