/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    let [differ,ans] = [Number.MAX_VALUE,Number.MAX_VALUE];
    nums.sort((a,b)=>a-b);
    const n = nums.length;
    for(let i = 0; i<n; i++){
        let [l,r] = [i+1,n-1];
        while(l<r){
            const sum = nums[i] + nums[l] + nums[r];
            if(sum > target){
                if(differ > Math.abs(target-sum)){
                    ans = sum;
                    differ = Math.abs(target-sum);
                } 
                r--;
            }else if(sum < target){
                if(differ > Math.abs(target-sum)){
                    ans = sum;
                    differ = Math.abs(target-sum);
                }
                l++;
            }else{
                return sum;
            }
        }
    }
    return ans;
};