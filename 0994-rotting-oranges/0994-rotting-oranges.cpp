// same as count lever in tree pattern
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int length = 0, fresh = 0;
        queue<pair<int,int>> q;
        for(int i =0 ; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) {
                    q.push({i,j});
                    grid[i][j] = -2;
                }
            }
        }
        if(fresh == 0) return 0; // edge case
        while(!q.empty()){
            int n = q.size();
            for(int i =0; i<n; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                vector<pair<int,int>> neighbours = {{0,-1},{-1,0},{1,0},{0,1}};
                for(auto i : neighbours){
                    int new_r = r + i.first, new_c = c + i.second;
                    if(new_r<0 || new_c<0 || new_r>=row || new_c>=col || grid[new_r][new_c] == -2 || grid[new_r][new_c] == 0) continue;
                    // now grid[new_r][new_c] == 1)
                    grid[new_r][new_c] = -2;
                    fresh--;
                    q.push({new_r,new_c});
                }
            }
            length++;
        }
        if(fresh != 0) return -1;
        return length-1;
    }
};