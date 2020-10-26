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
    private int minDistance = 0;

    public int minDiffInBST(TreeNode root) {
        if(null != root.left) {
            minDistance = root.val - root.left.val;
        } else {
            minDistance = root.right.val - root.val;
        }
        preOrder(root);
        return minDistance;
    }

    private void preOrder(TreeNode node) {
        if(null == node) {
            return;
        } else {
            int distance = 0, distance1 = 0;
            if(null != node.left) {
                distance = node.val - traversalRight(node.left);
            }
            if(null != node.right) {
                distance1 = traversalLeft(node.right) - node.val;
                distance = distance < distance1 && distance > 0 ? distance : distance1;
            }
            minDistance = minDistance > distance && distance > 0 ? distance : minDistance;
        }

        preOrder(node.left);
        preOrder(node.right);
    }

    private int traversalLeft(TreeNode node) {
        while(null != node.left) {
            node = node.left;
        }

        return node.val;
    }

    private int traversalRight(TreeNode node) {
        while(null != node.right) {
            node = node.right;
        }

        return node.val;
    }
}