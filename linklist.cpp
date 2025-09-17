#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>

using namespace std;

class Node {
public:
  int data;
  class Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkList {

public:
  class Node *head;
  void insert(int data) {
    class Node *newNode = new Node(data);
    cout << endl;
    if (!head) {
      head = newNode;
      cout << data << "Inserted";
      return;
    }
    class Node *pointer = head;
    while (pointer->next) {
      pointer = pointer->next;
    }
    pointer->next = newNode;
    pointer = newNode;
    cout << "insered  : " << data;
  }
  void del(int pos) {
    cout << endl;
    if (head) {
      cout << "Empty LinkList";
      return;
    }
    if (pos == 1) {
      class Node *temp = head;
      head = head->next;
      cout << "head deleted  value  :" << temp->data;
      delete temp;
    }
    int count = 1, LinkSize = size();
    if (pos > LinkSize) {
      cout << "Position out of bound LinkList size is :" << LinkSize;
      return;
    }
    class Node *pointer = head, *previous = head;

    while (count != pos) {
      previous = pointer;
      pointer = pointer->next;
      cout << "previous at :" << previous->data
           << "pointer at :" << pointer->data << endl;
      count++;
    }
    cout << "pos " << pos << "data : " << pointer->data;
    previous->next = pointer->next;
    delete pointer;
  }
  int size() {
    class Node *pointer = head;
    int s = 0;
    while (pointer) {
      pointer = pointer->next;
      s++;
    }
    return s;
  }
} l1;

int main() {
  l1.insert(5);
  l1.insert(10);
  l1.insert(15);
  l1.insert(20);
  l1.insert(25);
  l1.del(6);
  l1.del(1);
  return 0;
}
