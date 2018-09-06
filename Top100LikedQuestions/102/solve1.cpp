//
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its level order traversal as:
//[
//  [3],
//  [9,20],
//  [15,7]
//]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        ans.push_back({});
        int cur = 0;
        int tail = 1;
        int level = 0;
        while (cur < tail) {
            auto node = nodes[cur];
            ans[level].push_back(node->val);
            if (node->left) nodes.push_back(node->left);
            if (node->right) nodes.push_back(node->right);
            cur++;
            if (cur == tail) {
                ans.push_back({});
                level++;
                tail = nodes.size();
            }
        }
        ans.pop_back();
        return ans;
    }
};
