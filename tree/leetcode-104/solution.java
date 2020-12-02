/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int maxDepth(TreeNode root) {
        int depth = 0;
        return preOrderTree(root, depth);
    }

    private int preOrderTree(TreeNode root, int depth) {
        if(null == root) {
            return depth;
        }

        depth++;
        int left = depth, right = depth;
        left = preOrderTree(root.left, depth);
        right = preOrderTree(root.right, depth);
        return left > right ? left : right;
    }
}