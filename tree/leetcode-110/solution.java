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
    public boolean isBalanced(TreeNode root) {
        return preOrder(root);
    }

    private boolean preOrder(TreeNode root) {
        if(null == root) return true;

        if(true == isBalancedHight(root)) {
            if(true == preOrder(root.left) && true == preOrder(root.right)) {
                return true;
            }
        }

        return false;
    }

    private boolean isBalancedHight(TreeNode root) {
        int leftHeight = maxDepth(root.left, 0);
        int rightHeight = maxDepth(root.right, 0);
        if(Math.abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return true;
    }

    private int maxDepth(TreeNode root, int depth) {
        if(null == root) {
            return depth;
        }

        depth++;
        if(null == root.left && null == root.right) {
            return depth;
        }

        int leftDepth = maxDepth(root.left, depth);
        int rightDepth = maxDepth(root.right, depth);
        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }
}