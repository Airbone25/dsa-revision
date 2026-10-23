class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            auto& temp = res.back();
            if(temp[1] >= intervals[i][0]){
                temp[0] = min(intervals[i][0],temp[0]);
                temp[1] = max(intervals[i][1],temp[1]);
            }else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
