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
    int minDepth(TreeNode* root) {
        // edge case
        if(root == NULL) return 0;
        int ans = 1;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left != NULL) q.emplace(curr->left);
                if(curr->right != NULL) q.emplace(curr->right);
                if(curr->left == NULL && curr->right == NULL) return ans;
            }
            ans++;
        }
        return -1;
    }
};