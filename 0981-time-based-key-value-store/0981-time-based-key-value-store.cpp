class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(ump.count(key)==0) return "";
        auto &arr = ump[key];
        int l = 0, r = arr.size()-1;
        string ans="";
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m].first<=timestamp){
                ans = arr[m].second;
                l = m+1;
            }else r=m-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */