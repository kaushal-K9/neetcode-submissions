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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);

        ListNode* prev = dummy;

        int carry = 0;

        while (l1 || l2 || carry) {

            int to_add = carry;

            if (l1) {
                to_add += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                to_add += l2->val;
                l2 = l2->next;
            }

            carry = to_add / 10;

            ListNode* temp = new ListNode(to_add % 10);
            prev->next = temp;
            prev = temp;
        }

        return dummy->next;
    }
};