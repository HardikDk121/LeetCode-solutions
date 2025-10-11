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
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;

    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});
    int max_width = 0;

    while (!q.empty()) {
      int level_size = q.size();
      unsigned long long start = q.front().second;
      unsigned long long end = q.back().second;
      max_width = max(max_width, int(end - start + 1));

      for (int i = 0; i < level_size; ++i) {
        auto [node, index] = q.front();
        q.pop();

        // Normalize index to prevent overflow
        index -= start;

        if (node->left)
          q.push({node->left, 2 * index + 1});
        if (node->right)
          q.push({node->right, 2 * index + 2});
      }
    }

    return max_width;
  }
};

// Helper to build simple tree manually
TreeNode *buildSampleTree() {
  /*
        1
       / \
      3   2
     / \   \
    5   3   9
  */
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(9);
  return root;
}

int main() {
  Solution sol;
  TreeNode *root = buildSampleTree();
  cout << "Maximum Width of Binary Tree: " << sol.widthOfBinaryTree(root)
       << endl;
  return 0;
}
