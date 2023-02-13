class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0;
        unordered_set<char> visited;
        while(r<s.size()){
            if(visited.find(s[r]) != visited.end()){
                ans = max(ans,r-l);
                // update window 
                while(s[l] != s[r]){
                    visited.erase(s[l]);
                    l++;
                }
                l++;
            }else{
                visited.insert(s[r]);
            }
            r++;
        }
        return max(ans,r-l);
    }
};