class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> temp;
        int mini = nums[0];
        temp.push_back(mini);
        vector<vector<int>> res;
        for(int i=1;i<n;i++){
            if((nums[i]-mini)<=k and temp.size()<3){
                temp.push_back(nums[i]);
            }else{
                res.push_back(temp);
                temp.clear();
                mini = nums[i];
                temp.push_back(mini);
            }
        }
        res.push_back(temp);
        if(res.size()*3>n) return {};
        return res;
    }
};