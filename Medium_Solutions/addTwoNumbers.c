#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};
int main(int argc, char *argv[]) { return 0; }
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  int carry = 0, sum = 0;
  struct ListNode *head = NULL, *tail = NULL;

  while (l1 != NULL || l2 != NULL || carry > 0) {
    struct ListNode *newnode =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    sum = carry;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }
    carry = sum / 10;
    newnode->val = sum % 10;
    newnode->next = NULL;

    if (head == NULL) {
      head = newnode;
      tail = newnode;
    } else {
      tail->next = newnode;
      tail = newnode;
    }
  }
  return head;
}
