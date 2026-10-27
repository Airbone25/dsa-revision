class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>> atlantic(rows,vector<bool>(cols,false));

        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;

        for(int c=0;c<cols;c++){
            pq.push({0,c});
            aq.push({rows-1,c});
        }

        for(int r=0;r<rows;r++){
            pq.push({r,0});
            aq.push({r,cols-1});
        }

        bfs(heights,pacific,pq);
        bfs(heights,atlantic,aq);

        vector<vector<int>> res;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;

    }

    void bfs(vector<vector<int>>& heights,vector<vector<bool>>& ocean,queue<pair<int,int>>& q){
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            ocean[r][c] = true;

            for(auto d:dir){
                int row = r+d.first;
                int col = c+d.second;

                if(row >= 0 && col >=0 && row < heights.size() && col < heights[0].size() && !ocean[row][col] && heights[r][c] <= heights[row][col]){
                    q.push({row,col});
                    
                }
            }
        }
    }
};
