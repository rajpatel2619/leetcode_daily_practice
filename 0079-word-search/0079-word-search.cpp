class Solution {
public:
    bool func(int r, int c, vector<vector<char>>& board, string word, int index){
        if(index==word.size()) return true;
        int m = board.size();
        int n = board[0].size();

        int dir[5] = {-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = r+dir[i];
            int nc = c+dir[i+1];
            if(nr>=0 and nr<m and nc>=0 and nc<n){
                
                if(board[nr][nc]== word[index]){
                    char c = board[nr][nc];
                    board[nr][nc]='1';
                    if(func(nr, nc, board, word, index+1))
                        return true;
                    board[nr][nc]=c;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    char c = board[i][j];
                    board[i][j] = '1';
                    if(func(i, j, board, word,1))
                        return true;
                    board[i][j] = c;
                }
            }
        }
        return false;
    }
};