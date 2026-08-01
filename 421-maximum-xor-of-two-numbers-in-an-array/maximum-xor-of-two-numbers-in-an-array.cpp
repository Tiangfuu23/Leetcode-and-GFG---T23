const int k = 2;
const int bit_length = 30;
class Trie {
    public:
        Trie* children[k];
        bool isEnd;
        
        Trie(){
            isEnd = false;
            for(int i = 0; i<k; i++){
                children[i] = nullptr;
            }
        }
};

class Solution {
public:
    // string conver2BinaryFormat(int n){ // O(logn)
    //     string b = "";
    //     while(n != 0){
    //         b = to_string(n % 2) + b;
    //         n = n/2; 
    //     }

    //     return b;
    // }

    void insert(Trie* root, const int& num){
        Trie* current_node = root;
        for(int i = bit_length; i >= 0; i--){
            int i_bit = 1 & (num >> i);
            if(current_node->children[i_bit] == nullptr){
                current_node->children[i_bit] = new Trie();
            }
            current_node = current_node->children[i_bit];
        }

        current_node->isEnd = true;
    }

    int findMaximumXOR(vector<int>& nums) {
        // build trie
        Trie* root = new Trie();
        for(int n : nums){
            insert(root, n);
        }

        int ans = 0;
        for(int n : nums){
            Trie* current_node = root;
            int temp = 0;
            for(int i = bit_length; i >= 0; i--){
                int i_bit = 1 & (n >> i);
                if(current_node->children[1-i_bit] != nullptr){
                    temp = temp | (1<<i);
                    current_node = current_node->children[1-i_bit];
                }else{
                    current_node = current_node->children[i_bit];
                }
            }
            ans = max(ans, temp);
        }

        return ans;
    }
};