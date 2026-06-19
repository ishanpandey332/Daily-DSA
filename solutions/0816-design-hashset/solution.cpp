class MyHashSet {
    private:
    bool data[1000001];
public:
    MyHashSet() {
        memset(data, false, sizeof(data));

        
    }
    
    void add(int key) {
        data[key]=true;
        
    }
    
    void remove(int key) {
        data[key]=false;
    }
    
    bool contains(int key) {
        return data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
