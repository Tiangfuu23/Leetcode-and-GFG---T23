/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const permutation = [];
    const res = [];
    const chosen = new Set();
    const search = function(){
        if(permutation.length === nums.length) res.push(Array.from(permutation));
        else{
            for(let i = 0; i<nums.length; i++){
                if(chosen.has(nums[i])) continue;
                chosen.add(nums[i]);
                permutation.push(nums[i]);
                search();
                chosen.delete(nums[i]);
                permutation.pop();
            }
        }
    }
    search();
    return res;
};