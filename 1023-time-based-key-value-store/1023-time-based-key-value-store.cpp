class TimeMap {
    unordered_map<string,vector<pair<string,int>>>m;    

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()){
            return "";
        }
        int low=0;
        int high = m[key].size() -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (m[key][mid].second < timestamp) {
                low = mid + 1;
            } else if (m[key][mid].second > timestamp) {
                high = mid - 1;
            } else {
                return m[key][mid].first;
            }
        }
        
        if (high >= 0) {
            return m[key][high].first;
        }
        return "";
    }

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */