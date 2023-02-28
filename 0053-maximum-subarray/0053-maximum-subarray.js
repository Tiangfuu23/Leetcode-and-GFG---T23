/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let global_max = nums[0];
    for(let i = 1; i<nums.length; i++){
        nums[i] = Math.max(nums[i-1] + nums[i], nums[i]);
        global_max = Math.max(global_max,nums[i]);
    }
    return global_max;
};