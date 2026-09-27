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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy(0);
        
        ListNode* needle = &dummy;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                needle->next = l1;
                l1 = l1->next;
            } else {
                needle->next = l2;
                l2 = l2->next;
            }
            needle = needle->next;
        }

        needle->next = l1? l1 : l2;

        return dummy.next;
        
    }
};