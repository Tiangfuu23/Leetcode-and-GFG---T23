class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        typedef long long ll;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        ll n = nums.size();
        for(int i =0; i<n; i++){
            int cur1 = nums[i];
            if(i>0 && cur1 ==nums[i-1]) continue; 
            for(int j = i + 1; j<n;j++){
                int cur2 = nums[j];
                if(j>i+1 && cur2 == nums[j-1]) continue;
                int l = j+1,r=n-1;
                while(l<r){
                    ll sum = (long long)cur1+cur2+nums[l]+nums[r];
                    if(l>j+1 && nums[l] == nums[l-1]) l++;
                    else if(sum> target) r--;
                    else if(sum < target) l++;
                    else{
                        res.push_back({cur1,cur2,nums[l],nums[r]});
                        l++;
                    }
                }
            }
        }
    return res;
    }
};