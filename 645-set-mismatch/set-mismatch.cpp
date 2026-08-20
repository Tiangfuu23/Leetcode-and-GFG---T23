class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isExist(n);
        vector<int> ans;
        int sum = 0;
        for(int& i : nums){
            if(isExist[i-1]){
                ans.push_back(i);
            }else{
                sum += i;
                isExist[i-1] = true;
            }
        }

        ans.push_back((n*(n+1)/2) - sum);
        return ans;
    }
};