class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p:prerequisites){
            int course = p[0];
            int prerequisite = p[1];
            adj[course].push_back(prerequisite);
        }

        vector<int> seen(numCourses,0);

        for(int i=0;i<numCourses;i++){
            stack<pair<int,bool>> s;
            s.push({i,false});
            while(!s.empty()){
                auto [curr,done] = s.top();
                s.pop();

                if(done){
                    seen[curr] = 2;
                    continue;
                }
                if(seen[curr] == 1){
                    return false;
                }
                if(seen[curr] == 2){
                    continue;
                }

                seen[curr] = 1;
                s.push({curr,true});

                for(int p:adj[curr]){
                    s.push({p,false});
                }
            }
        }

        return true;
    }
};
