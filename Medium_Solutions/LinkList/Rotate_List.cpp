// fellas!!
// this is the code for rotating a linked lists on LC
// but i observed an weird thing in the code
// in the code i have commented 3 lines at the last
// those are head a and temp pointers that im able to print but not able to do
// any operation

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 */
#include <istream>
using namespace std;
struct ListNode {
  int *val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
};
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {

    if (!head || !(head->next))
      return head;
    int size = 0;
    for (ListNode *temp = head; temp; temp = temp->next)
      size++;
    k = k % size;
    if (k == 0) {
      return head;
    }
    int flg = size - k - 1;
    ListNode *part = head;
    while (flg > 0) {
      part = part->next;
      flg--;
    }

    // ListNode *newSt = part->next;
    ListNode *temp = part->next;

    while (temp->next != nullptr) {
      temp = temp->next;
    }
    cout << part->val << endl;
    // cout<<newSt->val<<endl;
    cout << temp->val << endl;
    cout << head->val << endl;
    temp->next = head; // try running the code in LC without uncommenting this
                       // line and try with uncommenting this line
    head = part->next; // these three commented line is the reverse logic
    part->next = nullptr;

    return head;
  }
};
