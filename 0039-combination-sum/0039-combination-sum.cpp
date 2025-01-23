class Solution {
public:
    void func(int i, vector<int>&nums, int tar, vector<int> &ans, vector<vector<int>>&res){
        if(i==nums.size()){
            if(tar==0){
                sort(ans.begin(), ans.end());
                res.push_back(ans);
            }
            return;
        }

        //take
        if(nums[i]<=tar){
            ans.push_back(nums[i]);
            func(i, nums, tar-nums[i], ans, res);
            ans.pop_back();
        }
        //ntake
        func(i+1, nums, tar, ans, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        func(0, nums, target, ans, res);
        //
        for(auto v:res){
            for(auto e:v)
                cout<<e<<" ";
            cout<<endl;
        }
        return res;
    }
};