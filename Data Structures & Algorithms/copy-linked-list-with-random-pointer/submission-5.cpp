/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;

        //insert deepcopy nodes in the list
        //just after the original
        while(curr) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }

        //now set the random pointers 
        curr = head;

        while (curr) {
            if (curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        //split the deepcopy list from the original
        //the curr and newCurr run through the list 
        //fetching original and deepcopy nodes respectively
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;

        while (curr) {
            curr->next = (curr->next? curr->next->next : NULL);
            newCurr->next = (newCurr->next? newCurr->next->next : NULL);

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};