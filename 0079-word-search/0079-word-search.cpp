class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(back_track(i,j,0,board,word)) return true;
            }
        }
    return false;
    }
public:
    bool back_track(int r, int c, int i, vector<vector<char>>& board, string& word){
       
        //int rows = board.size();
        //int cols = board[0].size();
        if(i==word.size()) return true; // goal
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c] != word[i] ) return false; // constrain
        // 
        // here board[r][c] == word[i]
        //char temp = board[r][c];
        board[r][c] = ' ';
        bool res = back_track( r-1,c,i+1, board,word) || back_track( r+1,c,i+1, board,word) || back_track( r,c-1,i+1, board,word) || back_track( r,c+1,i+1, board,word); //choice
        board[r][c] = word[i];
        return res;
    }
};