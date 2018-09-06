//Given a singly linked list, determine if it is a palindrome.
//
//Example 1:
//
//Input: 1->2
//Output: false
//Example 2:
//
//Input: 1->2->2->1
//Output: true
//Follow up:
//Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (!head || !(head->next)) return true;
        ListNode *slow, *fast, *prev;
        slow = fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        if (fast) {
            fast = slow->next;
        }
        else {
            fast = slow;
        }
        ListNode *tempHead2 = prev->next;
        prev->next = NULL;
        
        slow = reverseList(head);
        ListNode *tempHead1 = slow;
        bool flag = true;
        while (slow && fast) {
            flag = flag && (slow->val == fast->val);
            slow = slow->next;
            fast = fast->next;
        }
        head = reverseList(tempHead1);
        prev->next = tempHead2;
        return flag;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head, *temp;
        while (cur) {
            temp = cur;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
};

