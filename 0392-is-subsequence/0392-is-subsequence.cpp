class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n==0) return true;
        if( n > m ) return false;
        int j = 0;
        for(int i = 0; i<m; i++){
            if(t[i] == s[j]) j++;
            if(j==n) return true;
        }
        return false;
    }
};