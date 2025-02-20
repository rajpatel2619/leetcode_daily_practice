class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), end(nums));
        for(auto &str:nums){
            for(auto &ch:str){
                if(ch=='0'){
                    ch='1';
                    if(st.find(str)==st.end()) return str;
                    ch='0';
                }else{
                    ch='0';
                    if(st.find(str)==st.end()) return str;
                    ch='1';
                }
            }
        }
        return "do it!";
    }
};