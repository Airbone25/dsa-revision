class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> v;

        for (int i = 0; i < n; i++) {
            if (!v.count(i)) {
                stack<pair<int, int>> s;
                s.push({0, -1});

                while (!s.empty()) {
                    auto [node, parent] = s.top();
                    s.pop();
                    if (v.count(node)) {
                        return false;
                    }
                    for (int i : adj[node]) {
                        if (parent != i) {
                            s.push({i, node});
                        }
                    }
                    v.insert(node);
                }
            }
        }

        return true;
    }
};
