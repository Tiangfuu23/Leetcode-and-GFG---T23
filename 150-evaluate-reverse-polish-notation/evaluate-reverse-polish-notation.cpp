class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operations = {"+", "-", "*", "/"};

        for(string t : tokens){
            if(operations.contains(t)){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int temp;
                if(t == "+"){
                    temp = op2 + op1;
                }else if(t == "-"){
                    temp = op2 - op1;
                }else if(t == "*"){
                    temp = op2 * op1;
                }else {
                    temp = op2 / op1;
                }
                st.push(temp);
            }else{
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};