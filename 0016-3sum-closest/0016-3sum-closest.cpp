/*
[-4,-1,1,2]

*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int differ = INT_MAX;
        int ans = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            int curr = nums[i];
            int l = i +1, r= n-1;
            while(l<r){
                int sum = curr+nums[l] + nums[r];
                if(sum > target){
                    if(differ > abs(target-sum)){
                        ans = sum;
                        differ = abs(target-sum);
                    }
                    r--;
                }else if(sum < target){
                    if(differ > abs(target-sum)){
                        ans = sum;
                        differ = abs(target-sum);
                    }
                    l++;
                }else{
                    return target;
                }
            }
        }
    return ans;
    }
};