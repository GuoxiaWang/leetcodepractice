//Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//
//Example:
//Given a binary tree 
//          1
//         / \
//        2   3
//       / \     
//      4   5    
//Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
//Note: The length of path between two nodes is represented by the number of edges between them.
//
//

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
    int diameterOfBinaryTree(TreeNode* root) {
        depthOfBinaryTree(root);
        return diameter;
    }
    int depthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        if(root && !root->left && !root->right)
            return 0;
        int leftDepth = 0;
        int rightDepth = 0;
        if (root->left) {
            leftDepth = depthOfBinaryTree(root->left) + 1;
        }
        if (root->right) {
            rightDepth = depthOfBinaryTree(root->right) + 1;
        }
        if (diameter < leftDepth + rightDepth) {
            diameter = leftDepth + rightDepth;
        }
        return max(leftDepth, rightDepth);
    }
private:
    int diameter = 0;
};

