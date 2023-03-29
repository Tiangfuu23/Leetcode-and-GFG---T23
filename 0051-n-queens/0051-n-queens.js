/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    const col = new Array(n).fill(0);
    const diag1 = new Array(2*n).fill(0);
    const diag2 = new Array(2*n).fill(0);
    const ans = [], temp = [];
    const search = function(row){
        if(row === n){
            ans.push(Array.from(temp));
        }else{
            for(let i = 0; i<n; i++){
                if(col[i] || diag1[row+i] || diag2[row-i+n-1]) continue;
                col[i] = diag1[row+i] = diag2[row-i+n-1] = 1;
                let s = new String();
                for(let j = 0; j<n; j++){
                    if(j===i) s += 'Q';
                    else s += '.';
                }
                temp.push(s);
                search(row+1);
                temp.pop();
                col[i] = diag1[row+i] = diag2[row-i+n-1] = 0;
            }
        }
    }
    search(0);
    return ans;
};