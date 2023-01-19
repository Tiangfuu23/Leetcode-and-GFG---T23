/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // bfs using queue time O(n) space O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res; // edge case
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* temp_node = q.front(); q.pop();
                if(temp_node != NULL) temp.push_back(temp_node->val);
                if(temp_node->left != NULL) q.push(temp_node->left);
                if(temp_node->right != NULL) q.push(temp_node->right); 
            }
            res.push_back(temp);
        }
        return res;
    }
};