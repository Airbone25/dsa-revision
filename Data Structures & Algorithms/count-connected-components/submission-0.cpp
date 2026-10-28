class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        unordered_set<int> v;

        for(int i=0;i<n;i++){
            if(!v.count(i)){
                bfs(adj,v,i);
                res++;
            }
        }

        return res;
    }

    void bfs(unordered_map<int,vector<int>>& adj,unordered_set<int>& v,int start){
        queue<int> q;
        q.push(start);
        v.insert(start);
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            for(int neighbor:adj[vertex]){
                if(!v.count(neighbor)){
                    v.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
};

