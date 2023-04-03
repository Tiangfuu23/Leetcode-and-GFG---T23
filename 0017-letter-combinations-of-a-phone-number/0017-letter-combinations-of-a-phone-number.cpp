class Solution {
private:
    vector<string> ans;
    string temp = "";
public:
    void search(string digits, int k){
        if(k == digits.size()){
            // goal
            ans.push_back(temp);
        }else{
            int num = digits[k] - '0';
            int end = (num==7 || num ==9) ? 4:3;
            for(int i = 0; i< end; i++){
                char choice = 'a' + (num-2)*3 + i;
                if(num == 8 || num == 9) choice += 1;
                temp.push_back(choice);
                search(digits,k+1);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        search(digits,0);
        return ans;
    }
};