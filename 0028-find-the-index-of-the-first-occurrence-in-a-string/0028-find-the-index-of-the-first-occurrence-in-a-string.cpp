class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;
        int res = haystack.find(needle);
        return res == string::npos ? -1 : res;
    }
};