class Solution {
public:
    int count = 0;
    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> larr(nums.begin()+left, nums.begin()+mid+1);
        vector<int> rarr(nums.begin()+mid+1, nums.begin()+right+1);

        int j = 0;
        for (int i = 0; i < larr.size(); i++) {
            while (j < rarr.size() && (long long)larr[i] > 2LL * rarr[j]) {
                j++;
            }
            count += j;
        }

        int i=0;
        j=0;
        int  k = left;
        while(i<larr.size() and j<rarr.size()){
            
            if(larr[i]<=rarr[j])
                nums[k++] = larr[i++];
            else {
                nums[k++] = rarr[j++];
            }
            
        }
        while(i<larr.size())
            nums[k++] = larr[i++];
        while(j<rarr.size())
            nums[k++] = rarr[j++];
    }
    void mergeSort(vector<int>&nums, int left, int right){
        if(left==right) return;
        int mid = left+(right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        for(auto e:nums)
            cout<<e<<" ";
        return count;
    }
};