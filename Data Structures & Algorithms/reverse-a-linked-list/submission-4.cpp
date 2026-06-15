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
    ListNode* reverseList(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        //while curr points to a valid node
        while (curr != nullptr) {
            //create a checkpoint for curr for next loop
            ListNode* next = curr->next;

            //make curr node point back to prev
            curr->next = prev;

            //when curr moves ahead, prev becomes curr
            prev = curr;

            //transport curr to next node using checkpoint
            curr = next;
        }

        //when curr falls out, prev is pointing to linked list last node
        head = prev;

        return head;
    }
};