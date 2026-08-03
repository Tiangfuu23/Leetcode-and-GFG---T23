class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int bit_len = 30;
        int row_idx_count = 0;
        vector<vector<int>> trie(1, vector<int>(2, -1));
        // Build trie
        for(int n : nums){
            int current_node = 0;
            for(int i = bit_len; i>=0; i--){
                int i_bit = (n >> i) & 1;
                if(trie[current_node][i_bit] == -1){
                    trie[current_node][i_bit] = ++row_idx_count;
                    trie.push_back(vector<int>(2, -1));
                }
                current_node = trie[current_node][i_bit];
            }
        }

        //
        int ans = 0;
        for(int n : nums){
            int current_node = 0;
            int temp = 0;
            for(int i = bit_len; i >= 0; i--){
                int i_bit = (n >> i) & 1;
                if(trie[current_node][1-i_bit] != -1){
                    temp = temp | (1 << i);
                    current_node = trie[current_node][1-i_bit];
                }else{
                    current_node = trie[current_node][i_bit];
                }
            }
            ans = max(ans, temp);
        }

        return ans;
    }
};