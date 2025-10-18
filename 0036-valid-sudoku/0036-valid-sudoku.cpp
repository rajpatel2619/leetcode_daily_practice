class Solution {
public:
    bool rcheck(vector<vector<char>>& bd){
        set<char> st;
        int count = 0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(bd[i][j]!='.'){
                    count++;
                    st.insert(bd[i][j]);
                }
            }
            if(st.size()!=count) return false;
            st.clear();
            count = 0;
        }
        return true;
    }
    bool ccheck(vector<vector<char>>& bd){
        set<char> st;
        int count = 0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(bd[j][i]!='.'){
                    count++;
                    st.insert(bd[j][i]);
                }
            }
            if(st.size()!=count) return false;
            st.clear();
            count = 0;
        }
        return true;
    }
    bool check(vector<vector<char>>& bd, int r, int c){
        set<char> st;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(bd[i][j]!='.'){
                    if(st.count(bd[i][j])) return false;
                    st.insert(bd[i][j]);
                }
            }
        }
        return true;
    }
    bool bcheck(vector<vector<char>>& bd){
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!check(bd, i, j)) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& bd) {
        return rcheck(bd) and ccheck(bd) and bcheck(bd);
    }
};