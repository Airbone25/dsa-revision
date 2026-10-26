class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = bfs(grid,{i,j});
                    maxArea = max(maxArea,area);
                }
            }
        }

        return maxArea;
    }

    int bfs(vector<vector<int>>& grid,pair<int,int> start){

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push(start);
        grid[start.first][start.second] = 0;
        int area = 1;

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int q_size = q.size();
            for(int i=0;i<q_size;i++){
                auto [r,c] = q.front();
                q.pop();

                for(auto d:dir){
                    int row = r + d.first;
                    int col = c + d.second;

                    if(row >= 0 && col >= 0 && row<n && col<m && grid[row][col] == 1){
                        grid[row][col] = 0;
                        q.push({row,col});
                        area++;
                    }
                }
            }
        }

        return area;

    }
};
