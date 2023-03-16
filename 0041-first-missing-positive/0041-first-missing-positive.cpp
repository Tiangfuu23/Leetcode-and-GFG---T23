// time O(n) - worse case: O(n^2) space O(n)
// note that ans belongs to [1, len(nums)+1]; // worse case : stricly increasing order
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 1, n = nums.size();
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        for(; ans<=n; ans++) if(st.find(ans) == st.end()) return ans;
        return ans;
    }
};