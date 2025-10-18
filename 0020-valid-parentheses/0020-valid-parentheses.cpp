class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch:s){
            if(st.empty()){
                st.push(ch);
            }else if(ch=='{' or ch=='[' or ch=='(')
                st.push(ch);
            else{
                if(ch==']'){
                    if(st.top()!='[') return false;
                    else st.pop();
                }else if(ch=='}'){
                    if(st.top()!='{') return false;
                    else st.pop();
                }else{
                    if(st.top()!='(') return false;
                    else st.pop();
                }
            }
        }
        if(st.size()) return false;
        return true;
    }
};