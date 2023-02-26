/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2) {
    let [n,m] = [text1.length, text2.length];
    const dp = Array.from(Array(n+1),()=>{return Array(m+1)});
    for(let i = 0; i<=n; i++) dp[i][0] = 0;
    for(let i = 0; i<=m; i++) dp[0][i] = 0;
    for(let i = 1; i<=n; i++){
        for(let j = 1; j<=m; j++){
            if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
};