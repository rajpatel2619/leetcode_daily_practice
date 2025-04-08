class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int c = 0;
        int s = 0;
        for(int i=0;i<n;i++){
            while(mp.find(nums[i])!=mp.end()){
                c++;
                for(int j=0;j<3 && s<n ;j++){
                    mp.erase(nums[s++]);
                }
            }
            if(i<s) i=s;
            if(i<n)
                mp[nums[i]] = i;
        }
        return c;
    }
};