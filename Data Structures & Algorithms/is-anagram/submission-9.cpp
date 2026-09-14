class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char,int> m;
        unordered_map<char,int> n;

        for(const auto& c:s){
            m[c]++;
        }

        for(const auto& q:t){
            n[q]++;
        }

        if(m == n){
            return true;
        }
        return false;
    }
};
