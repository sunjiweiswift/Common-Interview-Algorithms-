#include <iostream>
#include <climits>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int MinDepth(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    int minDepth = INT_MAX;
    if (root->left != nullptr) {
        minDepth = min(minDepth, MinDepth(root->left));
    }
    if (root->right != nullptr) {
        minDepth = min(minDepth, MinDepth(root->right));
    }
    return minDepth + 1;
}

int main()
{
//        0
//       / \
//      1   2
//     / \
//    3   4
    TreeNode* head = new TreeNode(0);
    head->left = new TreeNode(1);
    head->right = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->left = new TreeNode(4);
    cout << MinDepth(head) << endl;
    return 0;
}