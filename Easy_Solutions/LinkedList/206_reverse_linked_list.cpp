#include <iostream>
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev, *current, *nextptr;
    if (!head)
      return head;

    current = head;
    if (!current->next)
      return head;
    while (current) {

      nextptr = nextptr->next;
      current->next = prev;
      prev = current;
      current = nextptr;
    }
    head->next = NULL;
    head = prev;
    return head;
  }
};
