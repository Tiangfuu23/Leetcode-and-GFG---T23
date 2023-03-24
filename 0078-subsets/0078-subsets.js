/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const n = nums.length;
    const res = [];
    const temp = [];
    const gen = (k)=>{
        if(k===n) res.push(Array.from(temp));
        else{
            gen(k+1);
            temp.push(nums[k]);
            gen(k+1);
            temp.pop();
        }
    }
    gen(0);
    return res;
};