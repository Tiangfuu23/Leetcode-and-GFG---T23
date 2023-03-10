class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max = 1;
        vector<pair<int,int>> len(n,make_pair(1,1));
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(len[j].first >= len[i].first){
                        len[i] = {len[j].first+1,len[j].second};
                    }else if(len[j].first == len[i].first - 1) len[i].second += len[j].second;
                }
                max = fmax(len[i].first,max);
            }
        }
        int ans = 0;
        for(auto pr : len){
            if(pr.first == max) ans += pr.second;
        }
        return ans; 
    }
};