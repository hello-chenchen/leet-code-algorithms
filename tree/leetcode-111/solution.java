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
    public int minDepth(TreeNode root) {
        if(null == root) {
            return 0;
        }

        return preOrder(root, 1);
    }

    private int preOrder(TreeNode root, int depth) {
        if(null == root.left && null == root.right) {
            return depth;
        } else if(null != root.left && null != root.right) {
            ++depth;
            int leftDepth = preOrder(root.left, depth);
            int rightDepth = preOrder(root.right, depth);
            return leftDepth < rightDepth ? leftDepth : rightDepth;
        } else if(null != root.left) {
            ++depth;
            return preOrder(root.left, depth);
        } else {
            ++depth;
            return preOrder(root.right, depth);
        }
    }
}