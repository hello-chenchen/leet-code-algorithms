import java.util.ArrayList;
import java.util.List;

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private List<String> result = new ArrayList<String>();
    public List<String> binaryTreePaths(TreeNode root) {
        if(null == root) return result;
        String temp = String.valueOf(root.val);
        if(null == root.left && null == root.right) {
            result.add(temp);
            return result;
        }


        preOrder(root.left, temp);
        preOrder(root.right, temp);

        return result;
    }

    private void preOrder(TreeNode root, String path) {
        if(null == root) {
            return;
        }

        path = path + "->" + root.val;

        if(null == root.left && null == root.right) {
            result.add(path);
            return;
        }

        preOrder(root.left, path);
        preOrder(root.right, path);
    }
}