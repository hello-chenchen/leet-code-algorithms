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
class Solution {
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

    private int sumNumber = 0;

    public int rangeSumBST(TreeNode root, int L, int R) {
        preOrder(root, L, R);

        return sumNumber;
    }

    private void preOrder(TreeNode node, int left, int right) {
        if(null == node) {
            return;
        }

        if(node.val < left) {
            preOrder(node.right, left, right);
            return;
        } else if(node.val > right) {
            preOrder(node.left, left, right);
            return;
        } else {
            sumNumber += node.val;
        }

        preOrder(node.left, left, right);
        preOrder(node.right, left, right);
    }
}