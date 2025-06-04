class Solution {
public:
    string answerString(string word, int nf) {
        if(nf==1) return word;
        string result="";
        int n = word.size();
        int mLen = n - nf+1;
        for(int i=0;i<n;i++){
            int len = min(mLen, n-i);
            result = max(result, word.substr(i, len));
        }
        return result;
    }
};