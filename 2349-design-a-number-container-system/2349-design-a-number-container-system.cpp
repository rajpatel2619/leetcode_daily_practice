class NumberContainers {
public:
    unordered_map<int, int> mp; // ind, num 
    unordered_map<int, set<int>> st; // number , set of Ind in asc
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int n = mp[index];
        st[n].erase(index);
        mp[index] = number;
        st[number].insert(index);
    }
    
    int find(int number) {
        if(st[number].size()==0)
            return -1;
        return *st[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */