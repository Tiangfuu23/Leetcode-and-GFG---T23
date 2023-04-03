/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if(!digits.length) return [];
    const map = new Map([
        ['2','abc'],
        ['3','def'],
        ['4','ghi'],
        ['5','jkl'],
        ['6','mno'],
        ['7','pqrs'],
        ['8','tuv'],
        ['9','wxyz']
    ])
    const ans = [];
    let temp = "";
    const search = function(k){
        if(k==digits.length) ans.push(temp);
        else{
            const str = map.get(digits[k]);
            for(let choice of [...str]){
                temp += choice;
                search(k+1);
                temp = temp.slice(0,-1);
            }
        }
    }
    search(0);
    return ans;
};