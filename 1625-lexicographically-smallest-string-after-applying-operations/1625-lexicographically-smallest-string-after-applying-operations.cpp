class Solution {
public:
    string rotate(string str, int b){
        int n = str.size();
        return str.substr(b, n-b)+str.substr(0, b);
    }
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        unordered_set<string> st;
        st.insert(s);
        string mini = s;
        while(!q.empty()){
            string str = q.front();
            q.pop();
            // rotate..
            string rstr = rotate(str, b);
            if(st.count(rstr)==0){
                st.insert(rstr);
                q.push(rstr);
                mini = min(mini, rstr);
            }
            // add..
            for(int i=1;i<str.size();i+=2){
                int v = str[i] - '0';
                v = (v+a)%10;
                str[i] = v+'0';
            }
            if(st.count(str)==0){
                st.insert(str);
                q.push(str);
                mini = min(mini, str);
            }
        }   
        return mini;
    }
};