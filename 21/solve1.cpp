//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4
//
//
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto* head = new ListNode(0);
        auto* node = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        while (l1) {
            node->next = l1;
            l1 = l1->next;
            node = node->next;
        }
        while (l2) {
            node->next = l2;
            l2 = l2->next;
            node = node->next;
        }
        node = head;
        head = node->next;
        delete node;
        node = nullptr;
        return head;
    }
};
