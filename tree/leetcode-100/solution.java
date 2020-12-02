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
    private boolean result = true;
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(null == p && null == q) {
            return true;
        }
        preOrderTree(p, q);

        return result;
    }

    private void preOrderTree(TreeNode rootLeft, TreeNode rootRight) {
        if(null == rootLeft && null == rootRight) {
            return;
        }

        if((null == rootLeft && null != rootRight) || (null != rootLeft && null == rootRight) || (null == rootLeft && null != rootRight) || (null != rootLeft && null == rootRight)) {
            result = false;
            return;
        }

        if(rootLeft.val != rootRight.val) {
            result = false;
            return;
        }

        preOrderTree(rootLeft.left, rootRight.left);
        preOrderTree(rootLeft.right, rootRight.right);
    }
}