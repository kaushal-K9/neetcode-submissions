class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) return NULL;
        //Inserting deepcopy nodes after each original
        Node* curr = head;

        while (curr) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }

        //setting the random pointers of deepcopies
        curr = head;

        while (curr) {
            if (curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        //splitting the list to obtain deepcopy nodes  
        curr = head;
        Node* newHead = head->next;
        Node* newcurr = newHead;

        while (curr) {
            curr->next = curr->next ? curr->next->next : NULL;
            newcurr->next = newcurr->next ? newcurr->next->next : NULL;

            curr = curr->next;
            newcurr = newcurr->next;
        }

        return newHead;


    }
};