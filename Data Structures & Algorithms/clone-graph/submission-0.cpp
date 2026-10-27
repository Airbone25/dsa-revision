/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<int,Node*> m;
        m[node->val] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            Node* curr_clone = m[curr->val];
            for(auto n:curr->neighbors){
                if(!m.count(n->val)){
                    m[n->val] = new Node(n->val);
                    q.push(n);
                }
                curr_clone->neighbors.push_back(m[n->val]);
            }
        }

        return m[node->val];
    }
};
