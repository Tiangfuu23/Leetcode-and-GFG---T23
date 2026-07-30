class Solution {
public:
    void dfs(int currentNode, vector<vector<int>>& next,
             vector<bool>& isEndOfWord, const string& currentString,
             string& ans) {
        if (isEndOfWord[currentNode] && currentString.size() > ans.size()) {
            ans = currentString;
        }

        for (int v = 0; v < next[currentNode].size(); v++) {
            int temp = next[currentNode][v];
            if (temp != 0 && isEndOfWord[temp]) {
                // cout << currentString << endl;
                dfs(next[currentNode][v], next, isEndOfWord,
                    currentString + char(v + 'a'), ans);
            }
        }
    }

    string longestWord(vector<string>& words) {
        vector<vector<int>> next(1, vector<int>(26, 0));
        vector<bool> isEndOfWord(1, false);
        int rowCounter = 1;

        for (string str : words) {
            int currentNode = 0;
            for (char c : str) {
                int charValue = c - 'a';
                if (next[currentNode][charValue] == 0) {
                    // insert
                    next.push_back(vector<int>(26, 0));
                    next[currentNode][charValue] = rowCounter++;
                    isEndOfWord.push_back(false);
                }
                currentNode = next[currentNode][charValue];
            }
            isEndOfWord[currentNode] = true;
        }

        string ans = "";
        dfs(0, next, isEndOfWord, "", ans);
        return ans;
    }
};