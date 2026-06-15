class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;

        Node* newHead = NULL;
        Node* prev = NULL;

        unordered_map<Node*, Node*> mp;

        //first pass: copy only val and create map
        while (curr) {
            Node* temp = new Node(curr->val);

            mp[curr] = temp;

            if (newHead == NULL) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }

            curr = curr->next;
        }

        curr = head;
        Node* newcurr = newHead;

        //second pass: store the values of random
        while (curr) {
            if (curr->random == NULL) {
                newcurr->random = NULL;
            } else {
                newcurr->random = mp[curr->random];
            }

            curr = curr->next;
            newcurr = newcurr->next;
        }

        return newHead;

        
    }
};