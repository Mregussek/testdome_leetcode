/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  void actualSwapPairs(ListNode* head)
  {
    if (head == nullptr or head->next == nullptr)
    {
      return;
    }

    int first = head->val;
    int second = (head->next)->val;

    head->val = second;
    head->next->val = first;

    swapPairs(head->next->next);
  }

  ListNode* swapPairs(ListNode* head) {
    actualSwapPairs(head);
    return head;
  }
};