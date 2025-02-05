class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c = 0;
        char p;
        vector<int> arr(26 , 0);
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                c++;
                arr[s1[i]-'a']++;
                arr[s2[i]-'a']--;
            }
            if(c>2) return false;
        }
        for(auto e:arr)
            if(e) return false;
        return true;
    }
};