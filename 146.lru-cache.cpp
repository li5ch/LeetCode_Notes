/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.count(key)==0) return -1;
        auto it=m[key];
        int val=it->second;
        l.erase(it);
        l.push_front({key,val});
        m[key]=l.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            l.erase(m[key]);
        }
        l.push_front({key,value});
        m[key]=l.begin();
        if(l.size()>cap){
            int k=l.back().first;
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

