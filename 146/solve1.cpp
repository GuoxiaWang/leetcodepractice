//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//Follow up:
//Could you do both operations in O(1) time complexity?
//
//Example:
//
//LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (listPos.find(key) != listPos.end()) {
            use(key);
            return cache[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
private:
    void use(int key) {
        if (listPos.find(key) != listPos.end()) {
            recentUsed.erase(listPos[key]); //delete from recentUsed, and reinsert to recentUsed
        }
        else if (recentUsed.size() >= capacity) {
            // need to delete least Recently used cache
            int tmpkey = recentUsed.back();
            recentUsed.pop_back();
            cache.erase(tmpkey);
            listPos.erase(tmpkey);
        }
        recentUsed.push_front(key);
        listPos[key] = recentUsed.begin();
    }
private:
    int capacity;
    list<int> recentUsed;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> listPos;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

