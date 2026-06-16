class LRUCache {
public:
    
    //custom node 
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k, int v) : key{k}, value{v}, next{nullptr}, prev{nullptr} {}
    };

    //object state
    int n;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        n = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* temp = mp[key];
        int val = temp->value;

        removeNode(temp);
        insertFront(temp);
        
        return val;
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

            Node* temp = new Node(key, value);
            insertFront(temp);
            mp[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */