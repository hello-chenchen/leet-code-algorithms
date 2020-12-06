import sun.reflect.generics.tree.Tree;

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
    public TreeNode invertTree(TreeNode root) {

        TreeNode node = null;
        node = invertOrder(root);

        return node;
    }

    private void printTree(TreeNode tree) {
        if(null == tree) return;

        System.out.println(tree.val);
        printTree(tree.left);
        printTree(tree.right);
    }

    private TreeNode invertOrder(TreeNode root) {
        if(null == root) {
            return null;
        }

        TreeNode node = new TreeNode(root.val);

        node.right = invertOrder(root.left);
        node.left = invertOrder(root.right);

        return node;
    }
}