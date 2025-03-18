class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int xr = nums[0];
        int xs = nums[0];
        int maxi = 1;
        int l= 0, r=1, n=nums.size();
        while(r<n){
            xr^=nums[r];
            xs+= nums[r];
            if(xr==xs){
                maxi = max(maxi, r-l+1);
            }else{
                while(l<=r && xr!=xs){
                    xr^=nums[l];
                    xs-=nums[l];
                    l++;
                }
            }
            r++;
        }
        return maxi;
    }
};