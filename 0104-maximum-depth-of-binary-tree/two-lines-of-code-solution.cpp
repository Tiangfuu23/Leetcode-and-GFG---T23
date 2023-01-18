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
        if(!root) return 0;
        return fmax(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};
