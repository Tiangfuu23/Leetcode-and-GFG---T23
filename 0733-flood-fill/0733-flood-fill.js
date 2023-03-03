/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, color) {
    const [row,col] = [image.length, image[0].length];
    const color_same = image[sr][sc];
    function dfs (r,c) {
        if(r<0 || c<0 || r>=row || c>=col || image[r][c] !== color_same || image[r][c] === color) return;
        image[r][c] = color;
        dfs(r,c+1);
        dfs(r,c-1);
        dfs(r-1,c);
        dfs(r+1,c);
    }
    dfs(sr,sc);
    return image;
};