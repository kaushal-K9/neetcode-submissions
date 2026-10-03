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
        
        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        Node* newHead = NULL;
        Node* linker = NULL;


        while (curr) {
            //create a copy node and store in map
            Node* temp = new Node(curr->val);
            mp[curr] = temp;

            if (newHead == NULL) {
                newHead = temp;
                linker = newHead;
            } else {
                //need linker to link the new list together
                linker->next = temp;
                linker = temp;
            }

            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;

        //second pass: fill with corresponding randoms from original
        //random of original, gives random of copied list
        while (curr) {
            if (curr->random == NULL) {
                newCurr->random = NULL;
            } else {
                newCurr->random = mp[curr->random];
            }

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};