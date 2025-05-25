class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> st;
        int len = 0;
        for(auto &w:words){
            swap(w[0], w[1]);
            if(st.find(w)!=st.end()){
                len+=4;
                st[w]--;
                if(st[w]<=0)
                    st.erase(w);
            }else{
                swap(w[0], w[1]);
                st[w]++;
            }
        }
        for(auto el:st)
            if(el.first[0]==el.first[1]){
                len+=2;
                break;
            }
        return len;
    }
};