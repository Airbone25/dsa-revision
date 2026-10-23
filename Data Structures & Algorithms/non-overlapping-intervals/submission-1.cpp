class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> temp;
        auto prev = intervals[0];
        int prevEnd = prev[1];

        int cnt = 0;

        for(int i=1;i<n;i++){
            if(prevEnd > intervals[i][0]){
                prevEnd = min(prevEnd,intervals[i][1]);
                cnt++;
            }else{
                prevEnd = intervals[i][1];
            }
        }

        return cnt;
    }
};
