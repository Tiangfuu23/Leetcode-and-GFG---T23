class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Time O(n)
        // Space O(n)
        vector<int> mp(1001, 0);
        for(int i = 0; i<target.size(); i++){
            mp[target[i]] += 1;
            mp[arr[i]] -= 1;
        }
        for(int num : mp) if(num) return false;
        return true;
    }
};