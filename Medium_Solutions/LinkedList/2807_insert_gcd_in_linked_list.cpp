#include <iostream>
#include <numeric>
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
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    if (!head || !head->next)
      return head;
    for (ListNode *current = head; current && current->next;
         current = current->next->next) {
      ListNode *gcdnode =
          new ListNode(std::gcd(current->val, current->next->val));
      gcdnode->next = current->next;
      current->next = gcdnode;
    }
    return head;
  }
};
