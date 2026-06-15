class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // save next
            curr->next = prev;           // reverse pointer
            prev = curr;                 // move prev
            curr = next;                 // move curr
        }
        return prev;
    }
};
