class Solution {
public:
    bool check(string s, string t){
        unordered_map<char,char> mp;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(mp.find(s[i]) == mp.end()){
                mp.insert({s[i],t[i]});
            }else{
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        if(check(s,t) && check(t,s)) return true;
        return false;
    }
};