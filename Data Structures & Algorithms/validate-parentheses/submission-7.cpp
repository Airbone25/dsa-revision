class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';

        stack<char> st;

        for(auto& i:s){
            if(m.count(i)){
                if(!st.empty() && m[i] == st.top()){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                st.push(i);
            }
        }

        return st.empty();
    }
};
