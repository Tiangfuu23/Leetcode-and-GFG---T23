/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    const res = [];
    const temp = [];
    let sum = 0;
    const search = function (k,sum) {
        if(sum > target) return;
        else if(sum === target) res.push(Array.from(temp));
        else{
            for(let i = k; i<candidates.length; i++){
                temp.push(candidates[i]);
                sum += candidates[i];
                search(i,sum);
                sum -= candidates[i];
                temp.pop();
            }
        }
    }
    search(0,sum);
    return res;
};