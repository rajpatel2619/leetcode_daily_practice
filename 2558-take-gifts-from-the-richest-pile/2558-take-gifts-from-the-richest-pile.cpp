class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        while(k--){
            sort(gifts.begin(), gifts.end());
            gifts[n-1] = sqrt(gifts[n-1]);
        }
        for(auto e:gifts)
            cout<<e<<" ";
        return accumulate(gifts.begin(), gifts.end(), 0L);
    }
};