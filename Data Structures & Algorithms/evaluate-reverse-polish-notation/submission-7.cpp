class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const auto& token:tokens){
            if(token == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int sum = a+b;
                s.push(sum);
            }else if(token == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int sum = b-a;
                s.push(sum);
            }else if(token == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int sum = a*b;
                s.push(sum);
            }else if(token == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int sum = b/a;
                s.push(sum);
            }else{
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};
