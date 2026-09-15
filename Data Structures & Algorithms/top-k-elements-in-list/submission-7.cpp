class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> m;

        for(int num:nums){
            m[num]++;
        }

        vector<pair<int,int>> temp;

        for(auto& i:m){
            temp.push_back({i.second,i.first});
        }

        sort(temp.rbegin(),temp.rend());

        for(int i=0;i<k;i++){
            result.push_back(temp[i].second);
        }

        return result;
    }
};
