class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            unordered_set<char> r;
            for(int j=0;j<m;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(r.count(board[i][j])){
                    return false;
                }else{
                    r.insert(board[i][j]);
                }
            }
        }

        for(int i=0;i<n;i++){
            unordered_set<char> c;
            for(int j=0;j<m;j++){
                if(board[j][i] == '.'){
                    continue;
                }
                if(c.count(board[j][i])){
                    return false;
                }else{
                    c.insert(board[j][i]);
                }
            }
        }

        for(int k=0;k<n;k++){
            unordered_set<char> sq;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row = (k/3)*3+i;
                    int col = (k%3)*3+j;
                    if(board[row][col] == '.'){
                        continue;
                    }
                    if(sq.count(board[row][col])){
                        return false;
                    }
                    sq.insert(board[row][col]);
                }
            }
        }

        return true;

    }
};
