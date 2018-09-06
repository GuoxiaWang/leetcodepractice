//Given a linked list, remove the n-th node from the end of list and return its head.
//
//Example:
//
//Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//
//Given n will always be valid.


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n < 0)
            return head;
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        if (cnt == n) {
            //remove head node;
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            tmp = nullptr;
            return head;
        }
        int k = cnt - n;
        ListNode* pre = nullptr;
        ptr = head;
        for (int i=0; i<k; i++) {
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = ptr->next;
        delete ptr;
        ptr = nullptr;
        return head;
        
    }
};
