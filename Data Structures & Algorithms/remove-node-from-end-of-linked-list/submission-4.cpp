/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode dummy(0);

        //we need dummy node if n = length of linked list
        //in which case, the head node itself will be removed
        //so some starting point needs to be preserved
        ListNode* end = &dummy;
        dummy.next = head;

        for (int i = 0; i <= n; i++) {
            end = end->next;
        }

        //eliminator lands just before the node
        //that is to be evicted
        ListNode* eliminator = &dummy;

        while (end) {
            end = end->next;
            eliminator = eliminator->next;
        }

        eliminator->next = eliminator->next->next;

        return dummy.next;
    }
};