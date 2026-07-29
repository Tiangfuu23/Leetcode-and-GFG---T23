class Solution {
public:
    string longestWord(vector<string>& words) {
        // Brutal force
        unordered_set<string> st;
        for(string str: words)
            st.insert(str);
        
        string ans = "";
        for(string str: words){
            string pref = "";
            bool isGood = true;
            for(char c : str){
                pref += c;
                if(!st.count(pref)){
                    isGood = false;
                    break;
                }
            }

            if(isGood && (pref.size() > ans.size() || (pref.size() == ans.size() && pref < ans)))
                ans = str;
        }

        return ans;
    }
};