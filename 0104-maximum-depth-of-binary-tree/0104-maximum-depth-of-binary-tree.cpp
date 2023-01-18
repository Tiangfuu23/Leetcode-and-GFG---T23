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
// maybe fint the height of tree ? 
// time O(n) space O(1)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int x = 0; int y = 0;
        x = dfs(root->left);
        y = dfs(root->right);
        return fmax(x,y) + 1;
    }
};