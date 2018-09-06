//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int d = 0;
        auto* head = new ListNode(0);
        auto* cur = head;
        while (l1 && l2) {
            int sum = l1->val + l2->val + d;
            d = sum / 10;
            auto* node = new ListNode(sum % 10);
            cur->next = node;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + d;
            d = sum / 10;
            auto* node = new ListNode(sum % 10);
            cur->next = node;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + d;
            d = sum / 10;
            auto* node = new ListNode(sum % 10);
            cur->next = node;
            cur = cur->next;
            l2 = l2->next;
        }   
        if (l1 == nullptr && l2 == nullptr && d > 0) {
            auto* node = new ListNode(d);
            cur->next = node;
            cur = cur->next;
        }
        cur = head;
        head = head->next;
        delete cur;
        cur = nullptr;
        return head;
        
    }
};
