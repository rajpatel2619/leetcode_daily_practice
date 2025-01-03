class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long sumt = accumulate(nums.begin(), nums.end(), 0ll);
        long long sumc = 0;
        int mini = INT_MAX, minInd = 0;
        for(int i=0;i<n;i++){
            sumt-=nums[i];
            sumc+=nums[i];
            int t = (n-i-1==0)?1:n-i-1;
            int curr = abs(sumc/(i+1)-sumt/t);
            cout<<curr<<" "<<i<<endl;
            if(mini > curr){
                mini = min(mini, curr);
                minInd = i;
            }
        }
        return minInd;
    }
};