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
    ListNode* reverseKNodes(ListNode* head, int k) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (k--) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //we go one node ahead of current k nodes
        //head is the original head which is now tail
        //and is linked to remaining list
        head->next = curr;

        return prev;
    }

    int findLength(ListNode* head) {
        ListNode* curr = head;
        int len = 0;

        while (curr) {
            len++;
            curr = curr->next;
        }

        return len;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //step 1: find length of the linked list
        int len = findLength(head);

        //step 2: finding first time reversal

        //we set prevGroupTail to nullptr to understand 
        //first K-size reversal happened
        //and set the head to newHead returned 
        //after reversing
        ListNode* prevGroupTail = nullptr;

        ListNode* curr = head;

        while (len >= k) {
            
            //step 2.1: we retain memory of our groupHead
            //before reversal
            ListNode* groupHead = curr;

            //get new head after reversal
            ListNode* newHead = reverseKNodes(curr, k);

            if (prevGroupTail == nullptr) {
                //first k-sized reversal occured
                // so we update the head
                head = newHead;
            } else {
                //for other reversals the next of 
                //previous group tail aka head before reversal
                //helps find the newHead to link to older head
                //which now sits at the last of previous group
                prevGroupTail->next = newHead;
            }

            //logically, after reversal
            prevGroupTail = groupHead;

            //step 3: initializing curr again
            //as reversal begins at curr
            //groupHead represents the head before reversal
            curr = groupHead->next;

            //decrement in k steps, so that we do not have
            //to reverse any remaining group less than k-size
            len -= k;
        }

        return head;

    }
};