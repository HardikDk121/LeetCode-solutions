#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    if (!head)
      return nullptr;

    // Skip initial nodes that match 'val'
    while (head && head->val == val)
      head = head->next;

    ListNode *prev = head;
    ListNode *ptr = (head ? head->next : nullptr);

    while (ptr) {
      if (ptr->val == val) {
        // Skip all consecutive nodes with 'val'
        while (ptr && ptr->val == val)
          ptr = ptr->next;
        if (prev)
          prev->next = ptr;
      }
      if (prev)
        prev = prev->next;
      if (ptr)
        ptr = ptr->next;
    }

    return head;
  }
};

// Utility function to create a linked list from a vector
ListNode *createList(const vector<int> &nums) {
  if (nums.empty())
    return nullptr;
  ListNode *head = new ListNode(nums[0]);
  ListNode *current = head;
  for (size_t i = 1; i < nums.size(); ++i) {
    current->next = new ListNode(nums[i]);
    current = current->next;
  }
  return head;
}

// Utility function to print the linked list
void printList(ListNode *head) {
  while (head) {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Solution sol;

  vector<int> values = {1, 2, 6, 3, 4, 5, 6};
  int valToRemove = 6;

  ListNode *head = createList(values);
  cout << "Original list: ";
  printList(head);

  head = sol.removeElements(head, valToRemove);

  cout << "After removing " << valToRemove << ": ";
  printList(head);

  return 0;
}
