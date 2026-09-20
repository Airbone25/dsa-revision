class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<char> m;
        int longest = 0;

        for(int r=0;r<s.length();r++){
            while(m.count(s[r])){
                m.erase(s[l]);
                l++;
            }
            m.insert(s[r]);
            longest = max(longest,r-l+1);
        }

        return longest;
    }
};
