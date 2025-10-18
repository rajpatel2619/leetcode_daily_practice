class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(auto str:strs){
            string copy = str;
            sort(copy.begin(), copy.end());
            ump[copy].emplace_back(str);
        }
        vector<vector<string>> res;
        for(auto it:ump)
            res.push_back(it.second);
        return res;
    }
};