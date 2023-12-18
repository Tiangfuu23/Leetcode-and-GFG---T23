class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        int longest = 0, n = s.length();
        for(int i = 0; i<n; i++){
            if(s.charAt(i) == '(') st.push(i);
            else{
                if(!st.isEmpty() && s.charAt(st.peek()) == '(') st.pop();
                else st.push(i);
            }
        }
        if(st.isEmpty()) return n;
        else{
            int l = 0, r = n - 1;
            while(!st.isEmpty()){
                l = st.pop();
                longest = Math.max(longest, r - l);
                r = l-1;
            }
            longest = Math.max(longest, r+1);
        }
        return longest;
    }
}