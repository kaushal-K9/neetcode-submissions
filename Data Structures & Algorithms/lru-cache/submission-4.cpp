class LRUCache {
public:
    vector<pair<int, int>> cache;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        //find the key, extract value, push pair to the back, return val

        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int val = cache[i].second;
                pair<int, int> temp = cache[i];

                cache.erase(cache.begin() + i);

                //updated {key, value} at the back again
                cache.push_back(temp);

                //return value
                return val;
            }
        }

        //no such key has been found
        return -1;
    }
    
    void put(int key, int value) {
        
        //find the key to update it
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        //no such key exists and we need to insert new
        //check the size of cache currently

        if (cache.size() == n) {
            //if cache is full, evict from front
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            //just push because there is space
            cache.push_back({key, value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */