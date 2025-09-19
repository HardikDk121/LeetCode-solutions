#include <bits/stdc++.h>
#include <cstddef>
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
struct queueLink {
  struct Node *current;
  struct queueLink *nextelement;
  queueLink(Node *node) {
    current = node;
    nextelement = NULL;
  }
} *front, *rear;
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
void level_order(Node *root) {
  if (!root)
    return;
  front = new queueLink(root);
  rear = front;
  int level = 1, nodecount = 1;

  while (front) {
    if (nodecount == level) {
      level = 2 * level;
      cout << endl;
    }
    cout << front->current->data << "\t";
    nodecount++;
    if (front->current->left) {
      rear->nextelement = new queueLink(front->current->left);
      rear = rear->nextelement;
    }
    if (front->current->right) {
      rear->nextelement = new queueLink(front->current->right);
      rear = rear->nextelement;
    }
    front = front->nextelement;
  }
}

void level_wise_order(Node *root) {
  if (!root)
    return;
  front = new queueLink(root);
  rear = front;
  int level = 1, nodecount = 1;
  int n;
  while (front) {
    for (int index = 0; index < n; index++) {

      if (nodecount == level) {
        level = 2 * level;
        cout << endl;
      }
      cout << front->current->data << "\t";
      nodecount++;
      if (front->current->left) {
        rear->nextelement = new queueLink(front->current->left);
        rear = rear->nextelement;
      }
      if (front->current->right) {
        rear->nextelement = new queueLink(front->current->right);
        rear = rear->nextelement;
      }
      front = front->nextelement;
    }
  }
}
void level_wise_order_vector(Node *node) {
  queue<Node *> nodes_queue;
  nodes_queue.push(node);
  bool rev_order = false;
  int prev = 1;
  while (!nodes_queue.empty()) {
    int n = nodes_queue.size();

    for (int index = 0; index < n; index++) {
      cout << nodes_queue.front()->data << "\t";
    }
    cout << endl;
    if (!rev_order) {

      if (nodes_queue.front()->left)
        nodes_queue.push(nodes_queue.front()->left);
      if (nodes_queue.front()->right)
        nodes_queue.push(nodes_queue.front()->right);
    } else {

      if (nodes_queue.front()->right)
        nodes_queue.push(nodes_queue.front()->right);
      if (nodes_queue.front()->left)
        nodes_queue.push(nodes_queue.front()->left);
    }
    nodes_queue.pop();
    if (prev != n) {
      rev_order = !rev_order;
      prev = n;
    }
  }
}
int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  cout << "pre order Traversel" << endl;
  pre_order(root);
  cout << endl << "In order Traversel" << endl;
  in_order(root);
  cout << endl << "Post order Traversel";
  post_order(root);
  cout << endl << "Level order Traversel" << endl;
  level_order(root);
  level_wise_order_vector(root);
  return 0;
}
