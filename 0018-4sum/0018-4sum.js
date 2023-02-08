/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    nums.sort((a,b)=>a-b);
    const n = nums.length;
    const res = [];
    for(let i = 0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        const cur1 = nums[i];
        for(let j = i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            const cur2 = nums[j];
            let [l,r] = [j+1,n-1];
            while(l<r){
                const sum = cur1+cur2+nums[l]+nums[r];
                if(l>j+1 && nums[l] == nums[l-1]) l++;
                else if(sum < target) l++;
                else if(sum > target) r--;
                else{
                    res.push([cur1,cur2,nums[l],nums[r]]);
                    l++;
                }
            }
        }
    }
    return res;
};