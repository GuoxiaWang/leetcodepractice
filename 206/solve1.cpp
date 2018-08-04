//Reverse a singly linked list.
//
//Example:
//
//Input: 1->2->3->4->5->NULL
//Output: 5->4->3->2->1->NULL
//Follow up:
//
//A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        auto* helper = new ListNode(0);
        helper->next = head;
        auto* pre = helper;
        auto* cur = head;
        while (cur && cur->next) {
            auto* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        if (cur)
            cur->next = pre;
        if (head) {
            head->next = nullptr;
        }
        head = cur;
        delete helper;
        helper = nullptr;
        return head;
    }
};

