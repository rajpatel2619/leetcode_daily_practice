// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<int> res;
//         int curr = nums[0];
//         int count = 1;
//         for(int i=1;i<n;i++){
//             if(nums[i]==curr) count++;
//             else{
//                 if(count>n/3) res.push_back(curr);
//                 curr = nums[i];
//                 count=1;
//             }
//         }
//         if(count>n/3) res.push_back(curr);
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int>mp;
//         for(auto e:nums)
//             mp[e]++;
//         vector<int> res;
//         for(auto [k, v]:mp)
//             if(v>n/3) res.push_back(k);
//         return res;
//     }
// };

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int c1=0, c2=0, el1, el2;
        for(int i=0;i<n;i++){
            if(c1==0 and nums[i]!=el2){
                c1++;
                el1 = nums[i];
            }
            else if(c2==0 and nums[i]!=el1){
                c2++;
                el2 = nums[i];
            }else if(el1==nums[i])
                c1++;
            else if(el2==nums[i])
                c2++;
            else {
                c1--;
                c2--;
            }
        }

        c1=0, c2=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]) c1++;
            else if(el2==nums[i]) c2++;
        }
        if(c1>n/3) res.push_back(el1);
        if(c2>n/3) res.push_back(el2);
        
        return res;
    }
};