class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n = p.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(p[j]<=p[i]){
        //             p[i]-=p[j];
        //             break;
        //         }
        //     }
        // }
        // return p;

        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            if(p[i]>p[st.top()])
                st.push(i);
            else{
                while(!st.empty() && p[i]<=p[st.top()]){
                    p[st.top()]-=p[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return p;
    }
};