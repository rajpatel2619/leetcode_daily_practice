class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res;
        int k = 0;
        for(auto e:nums)
            if(e<pivot)
                res.push_back(e);
            else if(e==pivot)
                k++;
        while(k--){
            res.push_back(pivot);
        }   
        for(auto e:nums)
            if(e>pivot)
                res.push_back(e);
        return res;
    }
};