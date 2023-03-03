class Solution {
public:
    static bool fcompare(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int& i : nums) temp.push_back(to_string(i));
        sort(temp.begin(), temp.end(), fcompare);
        string ans = "";
        for(auto s : temp) ans += s;
        // check edge case when first character is 0 -> all char is 0;
        if(ans[0] == '0') return "0";
        return ans;
    }
};