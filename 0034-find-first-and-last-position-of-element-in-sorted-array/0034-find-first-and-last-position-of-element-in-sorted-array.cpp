class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(nums[mid] == target){
                int temp = mid;
                while(l < temp){
                    int m = l + (temp-l)/2;
                    if(nums[m] == target) {
                        temp = m;
                    }
                    else l = m + 1; 
                }
                temp = mid;
                while(temp < r){
                    int m = temp + (r-temp)/2;
                    if(nums[m] != target) {
                        r = m;
                    }
                    else temp = m+1;
                }
                // temp -> position so that value != target
                if(nums[temp] == target) temp++;
                vector<int> ans = {l,temp-1};
                return ans;
            }else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
    vector<int> ans = {-1,-1};
    return ans;
    }
};
