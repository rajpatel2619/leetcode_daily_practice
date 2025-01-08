class Solution {
public:
    bool ok(string ptr, string str){
        return ptr.size()<=str.size() && ptr==str.substr(0, ptr.size()) && ptr==str.substr(str.size()-ptr.size(), ptr.size());
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ok(words[i], words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};