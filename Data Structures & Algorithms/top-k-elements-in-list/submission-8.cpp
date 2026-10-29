class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> m;

        for(int num:nums){
            m[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto& i:m){
            pq.push({i.second,i.first});
        }

        for(int i=0;i<k;i++){
            auto [freq,num] = pq.top();
            pq.pop();
            result.push_back(num);
        }

        return result;
    }
};
