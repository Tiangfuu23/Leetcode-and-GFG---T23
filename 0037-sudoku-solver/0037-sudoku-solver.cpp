class Solution {
private:
    bool row[10][10] = {false}, col[10][10] = {false}, grid[10][10] = {false};
public:
    bool isSafe(vector<vector<char>>& board, int i, int j, int num){
        return !(row[i][num] || col[j][num] || grid[i/3*3 + j/3][num]);
    }
    bool backTrack(vector<vector<char>>& board, int r, int c){
        if(r == 9) return true;
        if(c == 9 ) return backTrack(board,r+1,0);
        if(board[r][c] != '.') return backTrack(board,r,c+1);
        for(int num = 1; num<=9; num++){
            if(isSafe(board,r,c,num)){
                row[r][num] = col[c][num] = grid[r/3*3 + c/3][num] = true;
                board[r][c] = num + '0';
                if(backTrack(board,r,c+1)) return true;
                row[r][num] = col[c][num] = grid[r/3*3 + c/3][num] = false;
                board[r][c] = '.';
            }
        }
        return false;
    }     
    void solveSudoku(vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                row[i][num] = col[j][num] = grid[i/3*3+j/3][num] = true;
            }
        }
        backTrack(board,0,0);      
    }
};