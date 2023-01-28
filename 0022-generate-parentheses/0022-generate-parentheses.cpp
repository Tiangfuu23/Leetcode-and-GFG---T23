// goal : no of open parentheses = no of close parentheses = n
// choice and constraine : '(' if no of open paren < n and ')' if no of close paren < no of open paren
class Solution {
public:
    void backTrack(vector<string>& res, string& temp, int openParen, int closeParen, int n){
        if(openParen == n && closeParen == n){
            res.push_back(temp);
        }else{
            if(openParen < n){
                temp.push_back('(');
                backTrack(res,temp,openParen+1,closeParen,n);
                temp.pop_back();
            }
            if(closeParen < openParen){
                temp.push_back(')');
                backTrack(res,temp,openParen,closeParen+1,n);
                temp.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        backTrack(res,temp,0,0,n);
        return res;
    }
};