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
        vector<int> list;
        int result = pathDec(root, list, sum);
        if(!result) {
            for(int i = 0; i < list.size(); i++) {
                cout << "list[" << i << "]: " << list[i];
                cout << endl;
            }
            return true;
        }

        return false;
    }

    int pathDec(TreeNode* root, vector<int>& list, int total) {
        if(NULL == root) {
            // if(!total) {
            //     return 0;
            // }
            return -1;
        }

        cout << "val: " << root->val << " total: " << total << endl;

        total = total - root->val;
        cout << "total: " << total << endl;
        if(0 == total) {
            if(root->left == NULL && root->right == NULL) {
                cout << "push data: " << root->val << endl;
                list.push_back(root->val);
                return 0;
            } else {
                int result = pathDec(root->left, list, total);
                if(0 == result) {
                    return 0;
                } else {
                    return pathDec(root->right, list, total);
                }
            }
        } else {
            cout << "left: " << endl;
            int result = pathDec(root->left, list, total);
            cout << "result: " << result << endl;
            if(0 == result) {
                return 0;
            } else {
                return pathDec(root->right, list, total);
            }
        }
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
