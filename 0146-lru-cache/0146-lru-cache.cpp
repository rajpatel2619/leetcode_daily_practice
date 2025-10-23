class LRUCache {
public:
    int n;
    list<int> lru;
    // key - val, it
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        lru.erase(mp[key].second);
        lru.push_front(key);
        mp[key].second = lru.begin();
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            lru.erase(mp[key].second);
        }else if(mp.size()==n){
            int lk = lru.back();
            lru.pop_back();
            mp.erase(lk);
        }
        lru.push_front(key);
        mp[key]= {value, lru.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */