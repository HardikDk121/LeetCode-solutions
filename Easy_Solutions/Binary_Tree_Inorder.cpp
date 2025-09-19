
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
 * };

class Solution {
public:
    vector<int> myIntVector;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return myIntVector;
        inorderTraversal(root->left);
        myIntVector.push_back(root->val);
        inorderTraversal(root->right);

        return myIntVector;
    }
};*/
