/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    nums.sort((a,b)=>a-b);
    let ans = 1;
    for(let i of nums){
        if(i<=0) continue;
        else if(i == ans) ans++
        else if(i>ans) return ans;
    }
    return ans;
};