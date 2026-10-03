class LRUCache {
public:
    //develop a doubly linked list node
    //this will be helpful to remove a node

    //by directly arriving at its address using
    //and unordered map
    class Node {
        public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), 
        next(nullptr) {}
    };

    //the data structure consists of a list of dll nodes

    //and head and tail nodes link and delink respectively
    //recent nodes at front, least recent ones at the back
    int n;
    Node* head;
    Node* tail;
    
    //we store (key, address of node that stores val)
    unordered_map<int, Node*> mp;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertFront(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    //intialize DLL with a head and tail 
    LRUCache(int capacity) {
        n = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        else {
            Node* temp = mp[key];
            removeNode(temp);
            insertFront(temp);
            return temp->value;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            temp->value = value;
            removeNode(temp);
            insertFront(temp);
        } else {
            if (mp.size() == n) {
                Node* temp = tail->prev;
                removeNode(temp);
                mp.erase(temp->key);
                delete temp;
            }

            Node* node = new Node(key, value);
            insertFront(node);
            mp[key] = node;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */