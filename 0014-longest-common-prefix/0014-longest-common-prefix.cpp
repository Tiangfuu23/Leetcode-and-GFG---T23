class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = "";
        for(int i = 0; i<strs[0].size(); i++){
            for(int j = 1; j<strs.size(); j++){
                if(i == strs[j].size() || strs[0][i] != strs[j][i]) return temp;
            }
            temp += strs[0][i];
        }
    return temp;
    }
};
// time O(m*n);
// space O(1)