//You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
//Example:
//
//Input: [5,2,6,1]
//Output: [2,1,1,0] 
//Explanation:
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.

struct MyTreeNode {
    int val;
    MyTreeNode *left;
    MyTreeNode *right;
    int count;
    int smaller_count;
    MyTreeNode(int x) : val(x), left(NULL), right(NULL), count(1), smaller_count(0) {}
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        if (n == 0) return ans;
        ans[n-1] = 0;
        MyTreeNode* root = new MyTreeNode(nums[n-1]);
        for (int i=n-2; i>=0; i--) {
            ans[i] = insert(root, nums[i]);
        }
        return ans;
    }
    int insert(MyTreeNode* root, int val) {
        int smaller_count = 0;
        if (!root) return smaller_count;
        while (true) {
            if (val > root->val) {
                smaller_count += root->count + root->smaller_count;
                if (!root->right) {
                    root->right = new MyTreeNode(val);
                    break;
                }
                root = root->right;
            }
            else if (val < root->val) {
                root->smaller_count++;
                if (!root->left) {
                    root->left = new MyTreeNode(val);
                    break;
                }
                root = root->left;
            }
            else {
                root->count++;
                smaller_count += root->smaller_count;
                break;
            }
        }
        return smaller_count;
    }
};

