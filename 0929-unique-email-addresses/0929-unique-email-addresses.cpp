class Solution {
public:
    string modifyEmail(string str){
        string temp = "";
        int dest = str.find('@');
        for(int i = 0; i<dest; i++){
            if(str[i] == '.') continue;
            else if(str[i] == '+') break;
            temp += str[i];
        }
        temp += str.substr(dest);
        return temp;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> email;
        for(string str : emails){
            email.insert(modifyEmail(str));
        }
        return email.size();
    }
};