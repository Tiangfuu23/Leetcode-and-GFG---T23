/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
 // using array to implement queue -> time O(n) for operations in this queue
var minDepth = function(root) {
    if(root === null) return 0;
    let ans = 1;
    const queue = [root];
    while(queue.length){
        const n = queue.length;
        for(let i = 0; i<n; i++){
            let curr_node = queue.shift();
            if(curr_node.left !== null) queue.push(curr_node.left);
            if(curr_node.right !== null) queue.push(curr_node.right);
            if(curr_node.left === null && curr_node.right === null) return ans;
        }
        ans++;
    }
    return -1;
};