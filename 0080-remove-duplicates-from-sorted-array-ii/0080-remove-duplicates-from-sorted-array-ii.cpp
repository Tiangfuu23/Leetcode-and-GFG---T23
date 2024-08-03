class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int NEED_TO_REMOVED = 2301;
        int n = nums.size();
        int l = -1;
        int counter = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] == nums[i-1] && nums[i] == nums[i-2]) {
                if(l == -1) l = i;
                counter++;
                int j = i + 1;
                while(j < nums.size()){
                    if(nums[j] == nums[i]){
                        nums[j] = NEED_TO_REMOVED;
                        counter++;
                        j++;
                    }
                    else {
                        break;
                    };
                }
                nums[i] = NEED_TO_REMOVED;
                i = j - 1;
            }
        }
        if(l == -1) return n;
        int r = l + 1, k = n - counter;
        while(l < k){
            if(nums[l] == NEED_TO_REMOVED){
                while(r < n){
                    if(nums[r] != NEED_TO_REMOVED) {
                        int temp = nums[l];
                        nums[l] = nums[r];
                        nums[r] = temp;
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
};