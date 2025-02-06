class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto it:mp){
            int a = it.second;
            if(a>=2){
                c+=((a*(a-1))/2);
            }
        }
        return 8*c;
    }
};