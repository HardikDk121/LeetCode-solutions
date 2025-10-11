
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
  ListNode *swapPairs(ListNode *head) {
    for (ListNode *ptr = head; ptr && ptr->next; ptr = ptr->next->next) {
      int value = ptr->val;
      ptr->val = ptr->next->val;
      ptr->next->val = value;
    }
    return head;
  }
};
