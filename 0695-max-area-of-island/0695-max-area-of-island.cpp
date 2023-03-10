class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size(), col = grid[0].size();
        int offset[] = {1,0,-1,0,1};
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = 0;
                    int cnt = 0;
                    while(!q.empty()){
                        cnt++;
                        int curr_row = q.front().first;
                        int curr_col = q.front().second;
                        q.pop();
                        for(int k = 0; k<4; k++){
                            int r = curr_row + offset[k];
                            int c = curr_col + offset[k+1];
                            if(r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == 0) continue;
                            grid[r][c]  = 0;
                            q.push({r,c});
                        }
                    }
                    ans = fmax(ans,cnt);
                }
            }
        }
    return ans;
    }
};