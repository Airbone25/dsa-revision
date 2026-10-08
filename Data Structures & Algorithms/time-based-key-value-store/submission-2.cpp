class TimeMap {
    unordered_map<string,vector<pair<string,int>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!m.count(key)){
            return "";
        }
        auto& t = m[key];

        string ans = "";

        int l = 0;
        int r = t.size()-1;

        while(l<=r){
            int m = l+(r-l)/2;
            if(t[m].second<=timestamp){
                ans = t[m].first;
                l = m+1;
            }else{
                r = m-1;
            }
        }

        return ans;
    }
};
