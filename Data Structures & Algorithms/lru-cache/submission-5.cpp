class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key{k}, value{v}, prev{nullptr}, next{nullptr} {}
    };

    int n;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

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

    LRUCache(int capacity) {
        n = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
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
                //vacate a node to make space for a new node
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
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