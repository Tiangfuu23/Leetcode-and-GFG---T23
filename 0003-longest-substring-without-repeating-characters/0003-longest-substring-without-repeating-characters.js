/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let [l,r,ans] = [0,0,0];
    const visited = new Set();
    while(r<s.length){
        if(visited.has(s[r])){
            ans = Math.max(ans,r-l);
            // update window
            while(visited.has(s[r])){
                visited.delete(s[l]);
                l++;
            }
        }
        visited.add(s[r]);
        r++;
    }
    return Math.max(ans,r-l);
};