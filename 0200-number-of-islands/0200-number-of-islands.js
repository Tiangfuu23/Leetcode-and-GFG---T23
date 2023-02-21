/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const offset = [ 0,1,0,-1,0];
    let ans = 0;
    const [row,col] = [grid.length, grid[0].length];
    const dfs = function (i,j) {
        grid[i][j] = '0';
        for(let k = 0; k<4; k++){
            const [new_r,new_c] = [i+offset[k],j+offset[k+1]];
            if(new_r<0 || new_c < 0 || new_r>=row || new_c >= col || grid[new_r][new_c] == '0') continue;
            dfs(new_r,new_c);
        }
    }
    for(let i = 0; i<row; i++){
        for(let j = 0; j<col; j++){
            if(grid[i][j]==='1'){
                ans++;
                dfs(i,j)
            }
        }
    }
    return ans;
};