/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    const check = function(s,t){
        const mp = new Map();
        for(let i = 0; i<s.length; i++){
            if(mp.has(s[i])){
                if(mp.get(s[i]) != t[i]) return false
            }else{
                mp.set(s[i],t[i]);
            }
        }
        return true;
    }
    if(s.length != t.length) return false
    if(check(s,t) && check(t,s)) return true;
    return false;
};