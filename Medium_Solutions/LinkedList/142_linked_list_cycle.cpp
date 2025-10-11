
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
      return nullptr;
    if (head->next == head)
      return head;

    ListNode *slow = head->next;
    ListNode *fast = head->next->next;

    while (fast && fast->next) {
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
      slow = slow->next;
      fast = fast->next->next;
    }

    return nullptr;
  }
};

// Helper to create a linked list with cycle
ListNode *createLinkedListWithCycle(vector<int> &vals, int pos) {
  if (vals.empty())
    return nullptr;

  ListNode *head = new ListNode(vals[0]);
  ListNode *curr = head;
  ListNode *cycleNode = nullptr;

  for (int i = 1; i < vals.size(); ++i) {
    curr->next = new ListNode(vals[i]);
    curr = curr->next;
    if (i == pos)
      cycleNode = curr;
  }

  if (pos == 0)
    cycleNode = head;
  if (cycleNode)
    curr->next = cycleNode;

  return head;
}

int main() {
  Solution sol;
  vector<int> vals = {3, 2, 0, -4};
  int pos = 1; // cycle starts at index 1 (value 2)

  ListNode *head = createLinkedListWithCycle(vals, pos);
  ListNode *cycleStart = sol.detectCycle(head);

  if (cycleStart)
    cout << "Cycle detected at node with value: " << cycleStart->val << endl;
  else
    cout << "No cycle detected" << endl;

  return 0;
}
