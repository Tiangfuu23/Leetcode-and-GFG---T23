class Solution {
private:
    vector<int> col,diag1,diag2;
    vector<string> temp;
    vector<vector<string>> ans;
public:
    void search(int row, int n){
        if(row == n){
            ans.push_back(temp);
        }else{
            for(int i = 0; i<n; i++){
                if(col[i] || diag1[row+i] || diag2[row-i+n-1]) continue;
                col[i] = diag1[row+i] = diag2[row-i+n-1] = 1;
                string str(n,'.');
                str[i] = 'Q';
                temp.push_back(str);
                search(row+1,n);
                col[i] = diag1[row+i] = diag2[row-i+n-1] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->col.resize(n,0);
        this->diag1.resize(2*n,0);
        this->diag2.resize(2*n,0);
        search(0,n);
        return ans;
    }
};