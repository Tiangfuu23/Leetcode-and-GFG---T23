/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
    const ans = new Array(n+1).fill(0);
    for(let i = 1; i<=n; i++){
        ans[Math.floor(i)] = ans[Math.floor(i/2)] + i%2;
    }
    return ans;
};