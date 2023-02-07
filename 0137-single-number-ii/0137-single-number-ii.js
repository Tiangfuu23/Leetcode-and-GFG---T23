/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const map = new Map();
    for(let i = 0; i<nums.length; i++){
        if(map.has(nums[i])){
            let freq = map.get(nums[i]);
            freq++;
            map.set(nums[i],freq);
        }else{
            map.set(nums[i],1);
        } 
    }
    for(let i of map.keys()){
        if(map.get(i) == 1) return i;
    }
    return -1;
};