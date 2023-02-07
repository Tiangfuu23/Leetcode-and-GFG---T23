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
                if(nums[l]+nums[r] > target - curr){
                    if(differ > abs(target-curr-nums[l]-nums[r])){
                        ans = curr+nums[l]+nums[r];
                        differ = abs(target-curr-nums[l]-nums[r]);
                    }
                    r--;
                }else if(nums[l]+nums[r] < target - curr){
                    if(differ > abs(target-curr-nums[l]-nums[r])){
                        ans = curr+nums[l]+nums[r];
                        differ = abs(target-curr-nums[l]-nums[r]);
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