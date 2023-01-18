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
class Solution {
public:
    pair<int,int> dfs(TreeNode* root){
        // <diameter, height>
        if(root == NULL) return {0,-1};
        // postorder
        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);
        int diam = max({left.first,right.first,left.second+right.second+2});
        return {diam,max(left.second,right.second)+1};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
};