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
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ptr = dummy;
        ListNode* pre = dummy;
        for (int i=0; i<n; i++) {
            ptr = ptr->next;
        }
        while (ptr != nullptr && ptr->next) {
            ptr = ptr->next;
            pre = pre->next;
        }
        ptr = pre->next;
        pre->next = ptr->next;
        delete ptr;
        ptr = nullptr;

        return dummy->next;
    }
};
