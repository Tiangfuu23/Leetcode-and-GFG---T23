/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    const [row,col] = [grid.length, grid[0].length];
    let [ans,cnt] = [0,0];
    const dfs = function(r,c){
        if(r < 0 || c < 0 || r>= row || c >= col || grid[r][c] == 0) return;
        grid[r][c] = 0;
        cnt++;
        dfs(r+1,c);
        dfs(r-1,c);
        dfs(r,c-1);
        dfs(r,c+1);
    }
    for(let i = 0; i<row; i++){
        for(let j = 0; j<col; j++){
            if(grid[i][j] == 1){
                cnt = 0;
                dfs(i,j)
                ans = Math.max(ans,cnt);
            }
        }
    }
    return ans;
};