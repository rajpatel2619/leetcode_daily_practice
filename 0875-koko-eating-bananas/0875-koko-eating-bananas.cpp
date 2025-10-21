class Solution {
public:
    bool isPossible(vector<int> &nums, int m, int h){
        long count = 0;
        for(auto e:nums)
            count+=ceil(e/(1.0*m));
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(l<=r){
            int m = l + (r-l)/2;
            if(isPossible(piles, m, h)){
                ans = m;
                r = m-1;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};