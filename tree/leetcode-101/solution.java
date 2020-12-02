/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private boolean result = true;
    public boolean isSymmetric(TreeNode root) {
        if(null == root) {
            return true;
        }

        preOrderTree(root.left, root.right);

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

        preOrderTree(rootLeft.left, rootRight.right);
        preOrderTree(rootLeft.right, rootRight.left);
    }
}