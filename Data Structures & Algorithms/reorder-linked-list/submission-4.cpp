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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //split the list in half
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newhead = slow->next;
        slow->next = nullptr;

        //reverse the second list
        ListNode* prev = nullptr;
        ListNode* curr = newhead;

        while (curr) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //merge the two lists
        ListNode* h1 = head;
        ListNode* h2 = prev;
        
        //second list always exhausts before the first
        //as it is always smaller due to the way
        //fast and slow travel
        while (h2) {
            ListNode* t1 = h1->next;
            ListNode* t2 = h2->next;

            h1->next = h2;
            h2->next = t1;

            h1 = t1;
            h2 = t2;
        } 
    }
};