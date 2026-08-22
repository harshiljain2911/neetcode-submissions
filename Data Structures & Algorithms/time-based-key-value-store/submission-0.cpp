class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        int l = 0;
        int r = mp[key].size() - 1;

        if (mp[key].empty()) return "";

        while (l < r) {
            int mid = l + (r - l + 1) / 2;

            if (mp[key][mid].first <= timestamp) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }

        if (mp[key][l].first <= timestamp)
            return mp[key][l].second;

        return "";
    }
};