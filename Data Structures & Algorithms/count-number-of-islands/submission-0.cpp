class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    bfs(grid,{i,j});
                    cnt++;
                }
            }
        }

        return cnt;
        
    }

    void bfs(vector<vector<char>>& grid,pair<int,int> start){
        queue<pair<int,int>> q;
        q.push(start);

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto [r,c] = q.front();
                q.pop();

                for(auto d:dir){
                    int row = r+d.first;
                    int col = c+d.second;

                    if(row >= 0 && col >= 0 && row<grid.size() && col<grid[0].size() && grid[row][col] == '1'){
                        grid[row][col] = '0';
                        q.push({row,col});
                    }
                }
            }
        }
    }
};
