class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n);
        pref[0] = (isVowel(words[0][0]) && isVowel(words[0][words[0].size()-1]))?1:0;
        for(int i=1;i<n;i++){
            string w = words[i];
            pref[i] = pref[i-1]+((isVowel(w[0]) && isVowel(w[w.size()-1])));
        }
        vector<int> res;
        for(auto q:queries){
            if(q[0]==0)
                res.push_back(pref[q[1]]);
            else{
                res.push_back(pref[q[1]]-pref[q[0]-1]);
            }
        }
        return res;
    }
};