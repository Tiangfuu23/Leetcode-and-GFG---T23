/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    const freq = new Array(3).fill(0);
    nums.forEach(i => {
        freq[i]++;
    })
    let j = 0;
    for(let i = 0; i<=2; i++){
        while(freq[i]!=0){
            nums[j++] = i;
            freq[i]--;
        }
    }
};