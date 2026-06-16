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
        
        Node* newHead = nullptr;
        Node* prev = nullptr;

        Node* curr = head;

        unordered_map<Node*, Node*> mp;

        while (curr) {
            Node* temp = new Node(curr->val);

            //create a old to new node mapping
            mp[curr] = temp;

            //first node being added to the new list
            if (newHead == nullptr) {
                newHead = temp;
                prev = temp;
            } else {
                prev->next = temp;
                prev = temp;
            }

            curr = curr->next;
        }

        curr = head;
        Node* newcurr = newHead;

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