/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const map = new Map();
    for(let i = 0; i<nums.length; i++){
        map.set(nums[i], 1 + (map.has(nums[i]) ? map.get(nums[i]) : 0))
    }
    for(let i of map.keys()){
        if(map.get(i) == 1) return i;
    }
    return -1;
};