//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗            
//B:     b1 → b2 → b3
//begin to intersect at node c1.
//
//
//Notes:
//
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        auto* node = headA;
        while (node) {
            node = node->next;
            lenA++;
        }
        node = headB;
        while (node) {
            node = node->next;
            lenB++;
        }
        auto* pA = headA;
        auto* pB = headB;
        if (lenA < lenB) {
            int diff = lenB - lenA;
            while (diff--) {
                pB = pB->next;
            }
        }
        else if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) {
                pA = pA->next;
            }
        }
        while (pA && pB && pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};
