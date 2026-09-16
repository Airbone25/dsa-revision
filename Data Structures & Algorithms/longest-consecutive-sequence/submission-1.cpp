class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m(nums.begin(),nums.end());

        int longest = 0;

        for(int i:m){
            if(!m.count(i-1)){
                int length = 1;
                while(m.count(i+length)){
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};
