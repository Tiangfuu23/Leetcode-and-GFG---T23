class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size(), col = grid[0].size();
        vector<pair<int,int>> choices = {{0,-1},{0,1},{1,0},{-1,0}};
        for(int i =0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j]=='0') continue;
                // here grid[i][j] = '1'
                ans++;
                queue<pair<int,int>> q; // row - col
                q.emplace(i,j); 
                grid[i][j] = '0';
                while(!q.empty()){
                    int curr_row = q.front().first;
                    int curr_col = q.front().second;
                    q.pop();
                    for(pair<int,int>& i : choices){
                        int r = curr_row + i.first, c = curr_col + i.second;
                        if(r<0 || c <0 || r>=row || c>=col || grid[r][c] == '0') continue;
                        grid[r][c] = '0';
                        q.emplace(r,c);
                    }
                }
            }
        }
        return ans;
    }
};