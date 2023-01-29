class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[l] < nums[mid] && nums[mid] < nums[r]) return nums[l];
            else if(mid < r && nums[mid]>nums[mid+1]) return nums[mid+1];
            else if(mid>l && nums[mid-1] > nums[mid]) return nums[mid];
            else if(nums[mid] > nums[0]) l = mid+1;
            else r = mid - 1;
        }
        return nums[l];
    }
};