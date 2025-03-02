class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res;
        int f = 0;
        int s = 0;
        while(f<n1 && s<n2){
            if(nums1[f][0]==nums2[s][0]){
                res.push_back({nums1[f][0], nums1[f][1]+nums2[s][1]});
                f++;
                s++;
            }else if(nums1[f][0]<nums2[s][0]){
                res.push_back(nums1[f]);
                f++;
            }else{
                res.push_back(nums2[s]);
                s++;
            }
        }
        while(s<n2)
            res.push_back(nums2[s++]);
        while(f<n1)
            res.push_back(nums1[f++]);
        return res;
    }
};