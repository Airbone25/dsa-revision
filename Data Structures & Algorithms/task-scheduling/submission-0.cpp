class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> m;
        for(int task:tasks){
            m[task]++;
        }

        priority_queue<int> pq;
        for(auto [task,freq] : m){
            pq.push(freq);
        }

        queue<pair<int,int>> q;
        int cnt = 0;

        while(!pq.empty() || !q.empty()){
            cnt++;
            if(!pq.empty()){
                int task = pq.top();
                pq.pop();
                task--;
                if(task != 0){
                    q.push({task,cnt+n});
                }
            }

            if(!q.empty() && q.front().second == cnt){
                auto [task,time] = q.front();
                q.pop();
                pq.push(task);
            }
        }

        return cnt;

    }
};
