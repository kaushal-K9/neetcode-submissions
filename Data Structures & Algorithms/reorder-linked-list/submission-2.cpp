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
        
        ListNode* fast = head;
        ListNode* slow = head;

        //find the point to break linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //list after slow is shorter always
        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        
        //disconnect the list 
        slow->next = nullptr;

        //reverse second half
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }


    }
};