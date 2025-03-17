class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(501,0);
        int c = 0;
        for(int &e:nums){
            arr[e]++;
        }
        for(auto e:arr)
            if(e&1) 
                return false;
        return true;
    }
};