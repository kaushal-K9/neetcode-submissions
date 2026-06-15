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
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 || l2 || carry) {

            int sum = carry; //keep going on if carry exists

            if (l1) {  //keep going if list1 is not completely travelled
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {  //keep going if list2 is not completely travelled
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }

        return dummy->next;
    }
};