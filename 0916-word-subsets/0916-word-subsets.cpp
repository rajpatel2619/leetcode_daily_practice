class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<vector<int>> f(m, vector<int>(26,0));
        for(int i=0;i<m;i++){
            string w = words2[i];
            vector<int> temp(26,0);
            for(auto &ch:w){
                temp[ch-'a']++;
            }
            f[i] = temp;
        }

        //
        vector<string> res;
        for(int i=0;i<n;i++){
            string w = words1[i];
            vector<int> fq(26,0);
            for(auto &ch:w)
                fq[ch-'a']++;
            bool isOk = true;
            for(int j=0;j<m;j++){
                for(int k=0;k<26;k++){
                    if(fq[k]<f[j][k]){
                        isOk = false;
                        break;
                    }
                }
                if(!isOk)
                    break;
            }
            if(isOk)
                res.push_back(words1[i]);
        }
        return res;
    }
};