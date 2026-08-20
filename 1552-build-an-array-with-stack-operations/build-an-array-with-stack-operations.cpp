class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int pointer = 0;
        stack<int> st;
        string push = "Push", pop = "Pop";
        vector<string> ans;
        for(int i = 1; i<=n; i++){
            if(i != target[pointer]){
                st.push(i);
                ans.push_back(push);
                continue;
            }
            // i == target[pointer]
            while((pointer != 0 && st.top() != target[pointer -1]) || (pointer == 0 && !st.empty())){
                st.pop();
                ans.push_back(pop);
            }

            ans.push_back(push);
            st.push(i);
            pointer++;

            if(pointer == target.size())
                return ans;
        }

        return ans;
    }
};