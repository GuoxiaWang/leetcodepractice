//ven preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return buildTreeCore(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* buildTreeCore(vector<int>& preorder, int pre_l, int pre_r, vector<int>& inorder, int in_l, int in_r) {
        if (pre_r - pre_l == 0 || in_r - in_l == 0) return nullptr;
        int rootval = preorder[pre_l];
        int right_left_subtree = 0;
        for (int i=in_l; i<in_r; i++) {
            if (inorder[i] == rootval) {
                right_left_subtree = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootval);
        int len = right_left_subtree - in_l;
        root->left = buildTreeCore(preorder, pre_l+1, pre_l+1+len, inorder, in_l, in_l+len);
        root->right = buildTreeCore(preorder, pre_l+1+len, pre_r, inorder, right_left_subtree+1, in_r);
        return root;
    }
    
};
