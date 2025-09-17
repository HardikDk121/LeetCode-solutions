#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

typedef vector<int> vi;

struct Node {
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    next = nullptr;
    return;
  }
  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
} *head = NULL, *tail = NULL;
void playing_with_nodes(int data) {
  if (head == NULL) {
    head = new Node(data);
    tail = head;
    return;
  }
  struct Node *newNode = new Node(data);
  tail->next = newNode;
  tail = newNode;

  struct Node *print = head;
  while (print != NULL) {
    cout << "\t" << print->data;
    print = print->next;
  }
  cout << endl;
}

int main() {
  playing_with_nodes(5);
  playing_with_nodes(10);
  playing_with_nodes(15);
  playing_with_nodes(20);
  return 0;
}
