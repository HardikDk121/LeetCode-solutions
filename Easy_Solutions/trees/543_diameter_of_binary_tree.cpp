#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int height(TreeNode *root) {
    if (!root)
      return 0;

    int left_height = height(root->left);
    if (left_height == -1)
      return -1; // left subtree not balanced

    int right_height = height(root->right);
    if (right_height == -1)
      return -1; // right subtree not balanced

    if (abs(left_height - right_height) > 1)
      return -1; // current node not balanced

    return max(left_height, right_height) + 1;
  }

  bool isBalanced(TreeNode *root) { return height(root) != -1; }
};

// Helper to build a sample tree
TreeNode *buildSampleTree() {
  /*
        1
       / \
      2   3
     /
    4
  */
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  return root;
}

int main() {
  Solution sol;
  TreeNode *root = buildSampleTree();

  if (sol.isBalanced(root))
    cout << "The tree is balanced ✅" << endl;
  else
    cout << "The tree is not balanced ❌" << endl;

  return 0;
}
