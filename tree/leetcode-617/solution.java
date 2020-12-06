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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        return preOrderMerge(t1, t2);
    }

    private void printTree(TreeNode tree) {
        if(null == tree) return;

        System.out.println(tree.val);
        printTree(tree.left);
        printTree(tree.right);
    }

    private TreeNode preOrderMerge(TreeNode root, TreeNode node) {
        TreeNode result = null;
        if(null == root && null == node) {
            return result;
        } else if(null != root && null != node) {
            result = new TreeNode(root.val + node.val);
            result.left = preOrderMerge(root.left, node.left);
            result.right = preOrderMerge(root.right, node.right);
        } else if(null != root) {
            result = new TreeNode(root.val);
            result.left = preOrderMerge(root.left, null);
            result.right = preOrderMerge(root.right, null);
        } else {
            result = new TreeNode(node.val);
            result.left = preOrderMerge(node.left, null);
            result.right = preOrderMerge(node.right, null);
        }

        return result;
    }
}