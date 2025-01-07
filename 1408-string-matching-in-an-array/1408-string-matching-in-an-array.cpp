class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        int curr=0;
        while(curr<n){
            for(int i=0;i<n;i++){
                if(i==curr) continue;
                if(words[i].find(words[curr])!=string::npos){
                    res.push_back(words[curr]);
                    break;
                } 
            }
            curr++;
        }
        return res;
    }
};