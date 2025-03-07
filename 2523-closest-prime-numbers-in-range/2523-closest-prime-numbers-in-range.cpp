class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes(right+1, true);
        primes[0] = primes[1] = false;
        for(int i=2;i*i<=right;i++){
            if(primes[i]){
                for(int j=i*i;j<=right;j+=i)
                    primes[j] = false;
            }
        }
        vector<int> prs;
        for(int i=left;i<=right;i++)
            if(primes[i])
                prs.push_back(i);
        if(prs.size()<2) return {-1,-1};
        int ns = prs.size();
        int mini = prs[1]-prs[0];
        pair<int, int> p = {prs[0],prs[1]};
        for(int i=2;i<ns;i++){
            if(mini>(prs[i]-prs[i-1])){
                mini = prs[i] - prs[i-1];
                p.first = prs[i-1];
                p.second = prs[i];
            }
        }
        return {p.first, p.second};
    }
};