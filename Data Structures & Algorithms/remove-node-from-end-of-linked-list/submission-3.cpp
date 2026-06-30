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
        // ListNode* ahead = head;
        // ListNode* target = head;

        // for (int i = 0; i < n; i++) {
        //     ahead = ahead->next;
        // }

        // while (ahead) {
        //     ahead = ahead->next;
        //     target = target->next;
        // }

        //above approach fails for two reasons:
        //how do we remove the head when n == length of list? 
        //we need to land at a node before the target node to unlink target
        //node because it is a singly linked list

        ListNode dummy(0);
        dummy.next = head;

        ListNode* ahead = &dummy;
        ListNode* target = &dummy;

        //land n steps ahead of target pointer
        for (int i = 0; i < n; i++) {
            ahead = ahead->next;
        }

        //make the target pointer land ahead of target node
        //ahead pointer lands on the last node
        while (ahead->next) {
            ahead = ahead->next;
            target = target->next;
        }

        //target now sits a node before target node
        //remove it
        target->next = target->next->next;

        //return what dummy.next is, if head was the target
        //returning head will give a broken linked list
        return dummy.next;

    }
};