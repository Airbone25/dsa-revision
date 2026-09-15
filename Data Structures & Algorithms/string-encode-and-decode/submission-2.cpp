class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto& str:strs){
            res += to_string(str.length())+'#'+str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int slen = stoi(s.substr(i,j-i));
            i = j+1;
            string temp = s.substr(i,slen);
            res.push_back(temp);
            j = i+slen;
            i=j;
        }
        return res;
    }
};
