class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> f(maxi +1, 0); 
        for(auto e:nums) f[e]++;
        for(int i=1;i<f.size();i++)
            f[i]+=f[i-1];

        int res = 0;
        for (int el=mini;el<=maxi;el++) {
            int l = max(mini, el-k);
            int r = min(maxi, el+k);
            int fr = f[el]-f[el-1];
            int extra = min(numOperations, f[r]-f[l-1]-fr);
            res = max(res, fr+extra);
        }

        return res;
    }
};
