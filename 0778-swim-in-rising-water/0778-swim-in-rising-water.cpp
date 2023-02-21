class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        typedef tuple<int,int,int> tp; // height - rol - col
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n,false));
        priority_queue<tp, vector<tp>, greater<tp> > pq;
        pq.push({grid[0][0],0,0});
        visited[0][0] = true;
        while(!pq.empty()){
            int h,row,col;
            tie(h,row,col) = pq.top(); pq.pop();
            if(row==n-1 && col==n-1) return h;
            vector<pair<int,int>> choices {{0,-1},{-1,0},{1,0},{0,1}};
            for(pair<int,int>& i : choices){
                int new_rol = row + i.first, new_col = col + i.second;
                if(new_rol < 0 || new_rol >= n || new_col < 0 || new_col >= n || visited[new_rol][new_col]) continue;
                visited[new_rol][new_col] = true;
                pq.push({fmax(h,grid[new_rol][new_col]),new_rol,new_col});
            }
        }
    return -1; // it won't reach here 
    }
};