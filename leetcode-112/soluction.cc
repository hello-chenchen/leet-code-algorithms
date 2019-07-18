#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(NULL == root) {
            return false;
        }

        sum -= root->val;
        if(NULL == root->left && NULL == root->right) {
            return 0 == sum;
        }

        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    // TreeNode* bb = new TreeNode(5);
    // bb->left = new TreeNode(4);
    // bb->left->left = new TreeNode(11);
    // bb->left->left->left = new TreeNode(7);
    // bb->left->left->right = new TreeNode(2);
    // bb->right = new TreeNode(8);
    // bb->right->left = new TreeNode(13);
    // bb->right->right = new TreeNode(4);
    // bb->right->right->right = new TreeNode(1);
    // bool result = aa.hasPathSum(bb, 22);

    // TreeNode* bb = new TreeNode(1);
    // bb->left = new TreeNode(2);
    // bool result = aa.hasPathSum(bb, 1);
    TreeNode* bb = new TreeNode(-2);
    bb->right = new TreeNode(-3);
    bool result = aa.hasPathSum(bb, -5);
    cout << result << endl;
    return 0;
}
