class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time  = 0;

        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(fresh > 0 && !q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto [r,c] = q.front();
                q.pop();
                for(auto d:dir){
                    int row = r+d.first;
                    int col = c+d.second;

                    if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col] == 1){
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row,col});
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
