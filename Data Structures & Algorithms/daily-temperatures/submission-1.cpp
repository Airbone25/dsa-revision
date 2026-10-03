class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> s;
        vector<int> res(n,0);

        for(int i=0;i<n;i++){
            int t = temperatures[i];
            while(!s.empty() && t>s.top().first){
                auto pair = s.top();
                s.pop();
                res[pair.second] = i-pair.second;
            }
            s.push({t,i});
        }

        return res;
    }
};
