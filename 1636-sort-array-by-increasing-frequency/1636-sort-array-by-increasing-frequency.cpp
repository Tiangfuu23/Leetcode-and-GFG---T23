class Solution {
public:
    static bool fcompare(pair<int,int> a, pair<int,int> b){
        if(a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp; // value - freq
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(mp.count(nums[i])) mp[nums[i]]++;
            else mp.insert({nums[i],1});
        }
        vector<pair<int,int>> temp;
        for(pair<int,int> i : mp) temp.push_back(i);
        sort(temp.begin(), temp.end(), fcompare );
        vector<int> ans;
        for(auto& i : temp){
            while(i.second != 0){
                ans.push_back(i.first);
                i.second--;
            }
        }
        return ans;
    }
};