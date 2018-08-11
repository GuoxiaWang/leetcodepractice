//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
//Example:
//
//Input:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//Output: 1->1->2->3->4->4->5->6

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct mycomp {
  bool operator() (const ListNode* lhs, const ListNode* rhs) const {
      return lhs->val > rhs->val;
  }  
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        priority_queue<ListNode*, vector<ListNode*>, mycomp> pq;
        for (int i=0; i<lists.size(); i++) {
            if (lists[i])
                pq.push(lists[i]);
        }
        while (!pq.empty()) {
            ListNode* tmp_node = pq.top();
            pq.pop();
            node->next = tmp_node;
            node = node->next;
            if (tmp_node && tmp_node->next) {
                pq.push(tmp_node->next);
            }
        }
        node = head;
        head = head->next;
        delete node;
        node = NULL;
        return head;
    }
};
