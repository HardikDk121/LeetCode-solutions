#include <iostream>
using namespace std;
struct Node {
  int data;
  Node *left, *right;
  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};
void pre_order(Node *node) {
  if (!node)
    return;
  cout << "node :" << node->data << "\t";
  pre_order(node->left);
  pre_order(node->right);
}
void in_order(Node *node) {
  if (!node)
    return;
  in_order(node->left);
  cout << "node :" << node->data << "\t";
  in_order(node->right);
}
void post_order(Node *node) {
  if (!node)
    return;
  post_order(node->left);
  post_order(node->right);
  cout << "node :" << node->data << "\t";
}
int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->left->right = new Node(7);
  cout << "pre order Traversel" << endl;
  pre_order(root);
  cout << "In order Traversel" << endl;
  in_order(root);
  cout << "Post order Traversel" << endl;
  post_order(root);
  return 0;
}
