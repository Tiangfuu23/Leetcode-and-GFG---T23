class Solution {
public:
    string addBinary(string a, string b) {
        int maxLen = max(a.size(), b.size());
        string ans = "";
        int debt = 0;
        for(int i = 0; i < maxLen; i++){
            int x = i < a.size() ? a[a.size() - 1 - i] - '0' : 0;
            int y = i < b.size() ? b[b.size() - 1 - i] - '0' : 0;
            int new_bit = x + y + debt;
            debt = 0;
            // return to_string(x) + " || " + to_string(y);
            if(new_bit > 1) {
                new_bit = new_bit - 2;
                debt = 1;
            }
            ans = to_string(new_bit) + ans;
        }
        if(debt == 1) ans = "1" + ans;
        return  ans;
    }
};