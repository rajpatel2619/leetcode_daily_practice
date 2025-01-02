class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        queue<int> q;
        q.push(0);
        int far = 0;
        int n = s.size();
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            for(int i = max(ind + mn, far + 1);i<=min(ind+mx, n-1); i++){
                if(s[i]=='0'){
                    if(i==n-1) return true;
                    q.push(i);
                }
            }
            far = max(far, ind+mx);
        }
        return false;
    }
};