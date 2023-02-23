class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1) return 0;
        vector<vector<long long>> grid (row, vector<long long> (col));
        grid[0][0] = grid[row-1][col-1] = 1;
        for(int i = col-2; i>=0; i--){
            if(obstacleGrid[row-1][i] == 1){
                grid[row-1][i] = 0;
            }else{
                grid[row-1][i] = grid[row-1][i+1];
            }
        }
        for(int i = row-2; i>=0; i--){
            if(obstacleGrid[i][col-1] == 1){
                grid[i][col-1] = 0;   
            }else{
                grid[i][col-1] = grid[i+1][col-1];
            }
        }
        for(int i = row-2; i>=0; i--){
            for(int j = col-2; j>=0; j--){
                if(obstacleGrid[i][j] == 1) {
                    grid[i][j] = 0;
                }else{
                    grid[i][j] = grid[i+1][j] + grid[i][j+1];
                }
            }
        }
        return grid[0][0];
    }
};