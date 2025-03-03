class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        sort(strs.begin(), strs.end());
        int k = strs[0].size();
        for(int i=0;i<k;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[j-1][i])
                    return str;
            }
            str+=strs[0][i];
        }
        return str;
    }
};