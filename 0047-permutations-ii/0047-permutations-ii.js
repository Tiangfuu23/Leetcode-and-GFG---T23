/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    nums.sort((a,b)=>{return a-b});
    const chosen = new Array(nums.length).fill(false);
    const permutation = [];
    const res = [];
    let prev = Number.MAX_INTEGER;
    const search = function () {
        if(permutation.length === nums.length) res.push(Array.from(permutation));
        else{
            for(let i = 0; i<nums.length; i++){
                if(chosen[i]) continue;
                const choice = nums[i];
                if(choice === prev) continue;
                else prev = Number.MAX_INTEGER;
                chosen[i] = true;
                permutation.push(choice);
                search();
                chosen[i] = false;
                prev = permutation.pop(); 
            }
        }
    }
    search();
    return res;
};