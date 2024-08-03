public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int NEED_TO_REMOVED = 2301;
        int l = 0, n = nums.Length, cnt = 0;
        for(int i = 2; i < n; i++){
            if(nums[i] == nums[i-1] && nums[i] == nums[i-2]){
                if(l == 0) l = i;
                cnt++;
                int j = i + 1;
                while(j < n){
                    if(nums[j] == nums[i]){
                        nums[j] = NEED_TO_REMOVED;
                        cnt++;
                        j++;
                    }else break;
                }
                nums[i] = NEED_TO_REMOVED;
                i = j - 1;
            }
        }
        int k = n - cnt, r = l + 1;
        while(l < k){
            if(nums[l] == NEED_TO_REMOVED){
                while(r < n){
                    if(nums[r] != NEED_TO_REMOVED){
                        (nums[l], nums[r]) = (nums[r], nums[l]);
                        r++;
                        break;
                    }
                    r++;
                }
            }
            l++;
        }
        return k;
    }
}