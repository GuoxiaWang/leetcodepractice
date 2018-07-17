// Given a binary tree, flatten it to a linked list in-place.
// 
// For example, given the following tree:
// 
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
// 
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        flatten(right);  //first, we flatten right subtree
        if (left) {
            flatten(left); //then, we flatten left subtree
            root->left = nullptr;
            root->right = left;
            while(left->right) { //finally, we link right subtree to the last node of left subtree
                left = left->right;
            }
            left->right = right;
        }
    }
};
