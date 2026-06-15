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

         if (!head || !head->next) return;

        ListNode* fast = head;
        ListNode* middle = head;

        //find the middle of the linked list
        while (fast && fast->next) {
            middle = middle->next;
            fast = fast->next->next;
        }
        

        //reverse the second half of the linked list with middle as head 
        ListNode* curr = middle->next;
        middle->next = nullptr;
        ListNode* prev = nullptr;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //Merge the linked lists

        ListNode* first = head;
        ListNode* second = prev;

        //for odd length linked list, second list is shorter 
        while (second) {  //t1 and t2 guide by staying a node ahead
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }


    }
};
