/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    const [n,m] = [s.length,t.length];
    if(n>m) return false;
    let j = 0;
    for(let i = 0; i < m; i++){
        if(t[i] === s[j]) j++;
        if(j === n) return true;
    }
    return j === n;
};