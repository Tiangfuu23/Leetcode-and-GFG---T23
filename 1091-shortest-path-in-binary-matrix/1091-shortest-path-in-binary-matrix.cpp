class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // edge case
        queue<pair<int,int>> q; // row - col
        q.emplace(0,0);
        grid[0][0] = 1;
        while(!q.empty()){
            int r = q.front().first; // r = row 
            int c = q.front().second; // c = col
            q.pop();
            if(r-1>=0 && c-1>=0 && grid[r-1][c-1] == 0 ){
                q.emplace(r-1,c-1);
                grid[r-1][c-1] = grid[r][c] + 1;
            }
            if(r-1>=0 && grid[r-1][c] == 0){
                q.emplace(r-1,c);
                grid[r-1][c] = grid[r][c] + 1;
            }
            if(r-1>=0 && c+1<n && grid[r-1][c+1] == 0){
                q.emplace(r-1,c+1);
                grid[r-1][c+1] = grid[r][c] + 1;
            }
            if(c-1>=0 && grid[r][c-1] == 0){
                q.emplace(r,c-1);
                grid[r][c-1] = grid[r][c] + 1;
            }
            if(c+1<n && grid[r][c+1] == 0){
                q.emplace(r,c+1);
                grid[r][c+1] = grid[r][c] + 1;
            }
            if(r+1<n && c-1>=0 && grid[r+1][c-1] == 0){
                q.emplace(r+1,c-1);
                grid[r+1][c-1] = grid[r][c] + 1;
            }
            if(r+1<n && grid[r+1][c] == 0){
                q.emplace(r+1,c);
                grid[r+1][c] = grid[r][c] + 1;
            }
            if(r+1<n && c+1<n && grid[r+1][c+1] == 0){
                q.emplace(r+1,c+1);
                grid[r+1][c+1] = grid[r][c] + 1; 
            }
        }
    return grid[n-1][n-1] == 0 ? -1 : grid[n-1][n-1];
    }
};