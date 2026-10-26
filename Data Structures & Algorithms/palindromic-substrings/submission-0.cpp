class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();
        for(int i=0;i<s.length();i++){
            int l = i;
            int r = i;

            while(l>=0 && r<n && s[l] == s[r]){
                res++;
                l--;
                r++;
            }

            l = i;
            r = i+1;

            while(l>=0 && r<n && s[l] == s[r]){
                res++;
                l--;
                r++;
            }
        }

        return res;
    }
};
