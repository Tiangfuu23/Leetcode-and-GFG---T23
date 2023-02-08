class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp; // value - index;
        // find greatest element
        stack<pair<int,int>> s;
        for(int i = 0; i<nums2.size(); i++){
            mp.insert({nums2[i],i});
            int curr = nums2[i];
            while(!s.empty() && curr>s.top().first){
                nums2[s.top().second] = curr;
                s.pop();
            }
            s.push({curr,i});  
        }
        while(!s.empty()){
            nums2[s.top().second] = -1;
            s.pop();
        }
        for(int i = 0; i<nums1.size(); i++){
            nums1[i] = nums2[mp[nums1[i]]];
        }
        return nums1;
    }
};