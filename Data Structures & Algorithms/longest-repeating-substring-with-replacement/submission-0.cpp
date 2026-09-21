class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        unordered_map<char,int> m;
        int longest = 0;
        int maxf = 0;

        for(int r=0;r<s.length();r++){
            m[s[r]]++;
            maxf = max(maxf,m[s[r]]);

            while((r-l+1) - maxf > k){
                m[s[l]]--;
                l++;
            }

            longest = max(longest,r-l+1);
        }

        return longest;
    }
};
