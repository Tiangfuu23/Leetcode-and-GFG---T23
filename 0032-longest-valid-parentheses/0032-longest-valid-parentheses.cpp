class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> st;
        int ans = 0, n = str.length();
        for(int i = 0; i<n; i++){
            char c = str[i];
            if( c == '(') st.push(i);
            else{
                if(!st.empty() && str[st.top()] == '(') st.pop();
                else st.push(i);
            }
        }
        if(st.empty()) return str.length();
        else{
            int l = 0, r = str.length()-1;
            while(!st.empty()){
                l = st.top(); st.pop();
                ans = fmax(ans, r - l);
                r = l-1;
            }
            ans = fmax(ans, r+1);
        }
        return ans;
    }
};