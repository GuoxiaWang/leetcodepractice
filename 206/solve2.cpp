/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head && head->next) {
            auto* node = head->next;
            auto* tail = reverseList(head->next);
            node->next = head;
            head->next = nullptr;
            return tail;
        }
        else {
            return head;
        }
    }
};
