// /**
//  * @param {number[]} nums1
//  * @param {number[]} nums2
//  * @return {number[]}
//  */
// var nextGreaterElement = function(nums1, arr) {
//     const n = arr.length;
//     let ans = new Array(n).fill(-1);
//         let stack = []; // form [ [value,index] ]
//         for(let i = 0; i<n; i++){
//             const curr = arr[i];
//             while(stack.length && curr>stack.at(-1)[0]){
//                 ans[stack[stack.length-1][1]] = curr;
//                 stack.pop();
//             }
//             stack.push([curr,i]);
//         }
//     return ans;
// };
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, arr) {
    const n = arr.length;
    const temp = new Array(n).fill(-1); // for grater element 
    const map = new Map();
    const stack = []; // [ [value] index ]
    for(let i = 0; i<n; i++){
        const curr = arr[i];
        map.set(curr,i)
        while(stack.length && curr > stack.at(-1)[0]) temp[stack.pop()[1]] = curr;
        stack.push([curr,i]);
    }
    for(let i = 0; i<nums1.length; i++) nums1[i] = temp[map.get(nums1[i])];
    return nums1;
};