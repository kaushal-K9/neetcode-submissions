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


        //find the point to split the linked list
        //verifying fast->next ensures a valid point to jump to
        //verifying fast ensures current node is valid
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next; 
        }

        //new head for the second half of linked list 
        //that has to be separated
        ListNode* curr = slow->next;

       //split the list from where slow has landed
       slow->next = nullptr; 

       //reverse the second half
       ListNode* prev = nullptr;

       while (curr) {
        ListNode* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
       }

       //Now reorder both the lists, always in our method
       //the second half is shorter 

       ListNode* l1 = head;
       ListNode* l2 = prev;

       while (l2) {
        ListNode* t1 = l1->next;
        ListNode* t2 = l2->next;

        l1->next = l2;
        l2->next = t1;

        l1 = t1;
        l2 = t2;
        
       }

    }
};