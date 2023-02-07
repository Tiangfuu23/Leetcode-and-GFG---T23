class Solution {
public:
    // time O(n) spaceO(n) solution
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp; // value - freq
        for(int& i : nums){
            if(mp.find(i) != mp.end()) mp[i]++;
            else mp.insert({i,1});
        }
        for(auto i : mp){
            if(i.second == 1) return i.first;
        }
        return -1;
    }
};