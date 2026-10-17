class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        n = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>n){
            pq.pop();
        }
        return pq.top();
    }
};
