const int k = 26;
class Trie{
    public:
        Trie* children[k];
        bool endOfWord;

        Trie(){
            endOfWord = false;
            for(int i = 0; i < k; i++)
                children[i] = nullptr;
        }
};

void insert(Trie* root, const string& str){
    Trie* currentNode = root;
    for(char c : str){
        int charValue = c - 'a';
        if(currentNode->children[charValue] == nullptr){
            currentNode->children[charValue] = new Trie();
        }
        currentNode = currentNode->children[charValue];
    }
    currentNode->endOfWord = true;
}

void dfs(Trie* root, string str, string& ans){
    for(int i = 0; i < k; i++){
        if(root->children[i] != nullptr && root->children[i]->endOfWord){
            string temp = str + char('a' + i); 
            if(temp.size() > ans.size() || (temp.size() == ans.size() && temp < ans))
                ans = temp;
            dfs(root->children[i], temp, ans);
        }
    }
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* root = new Trie();
        for(string str : words)
            insert(root, str);
        string ans = "";
        dfs(root, "", ans);
        return ans;
    }
};