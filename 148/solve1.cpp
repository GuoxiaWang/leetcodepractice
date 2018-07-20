//Sort a linked list in O(n log n) time using constant space complexity.
//
//Example 1:
//
//Input: 4->2->1->3
//Output: 1->2->3->4
//Example 2:
//
//Input: -1->5->3->4->0
//Output: -1->0->3->4->5



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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto* slow = head;
        auto* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr; //patition
        slow = sortList(head);
        fast = sortList(fast);
        return mergeList(slow, fast);
    }
    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        auto* node1 = head1;
        auto* node2 = head2;
        auto* mergeHead = new ListNode(0);
        auto* cur = mergeHead;
        while (node1 && node2) {
            if (node1->val < node2->val) {
                cur->next = node1;
                node1 = node1->next;
            }
            else {
                cur->next = node2;
                node2 = node2->next;
            }
            cur = cur->next;
        }
        if (node1) {
            cur->next = node1;
        }
        if (node2) {
            cur->next = node2;
        }
        cur = mergeHead;
        mergeHead = mergeHead->next;
        delete cur;
        cur = nullptr;
        return mergeHead;
    }
};
