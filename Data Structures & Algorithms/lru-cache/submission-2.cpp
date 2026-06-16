class LRUCache {
public:
    int n;
    vector<pair<int, int>> cache;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    //if key found return value and push it back
    //or if not found return -1
    int get(int key) {
        
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                pair<int, int> temp = cache[i];

                //remove and insert at the back
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                
                return temp.second;
            }
        }

        return -1;
    }

    //if key already exists, update it with the value
    //and push it back
    //else remove the least recently used from front and
    //push new key,value into cache
    //first update then check size

    void put(int key, int value) {
        // if (cache.size() == n) {
        //     for (int i = 0; i < cache.size(); i++) {
        //         //if key found, update and push to the back
        //         if (cache[i].first == key) {
        //             //update value
        //             cache[i].second = value;
        //             pair<int, int> temp = cache[i];
        //             cache.erase(cache.begin() + i);
        //             cache.push_back(temp);
        //             return;
        //         } else {
        //             cache.erase(cache.begin());
        //             cache.push_back({key, value});
        //             return;
        //         }
        //     }
        // } else {
        //     cache.push_back({key, value});
        //     return;
        // }


        //above logic does not consider updation of a key, value pair if cache size
        //is less than capacity, it adds that key as well

        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache[i].second = value;
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return;
            }
        }

        //key not found, this is a new key
        if (cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
            return;
        } else {
            cache.push_back({key, value});
            return;
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */