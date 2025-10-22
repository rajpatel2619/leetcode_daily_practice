class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n;
        while(l<=r){
            int mid1 = l+(r-l)/2;
            int mid2 = (m+n+1)/2 - mid1;
            int nl = INT_MIN, nr = INT_MAX;
            int ml = INT_MIN, mr = INT_MAX;
            if(mid1-1>=0) nl = nums1[mid1-1];
            if(mid1<n) nr = nums1[mid1];
            if(mid2<m) mr = nums2[mid2];
            if(mid2-1>=0) ml = nums2[mid2-1];
            if(nl<=mr and ml<=nr){
                if((m+n)&1) return max(nl,ml);
                return (max(nl,ml)+min(nr, mr))/2.0;
            }else if(nl> mr) r = mid1-1;
            else l = mid1+1;
        }
        return 1.0;
    }
};