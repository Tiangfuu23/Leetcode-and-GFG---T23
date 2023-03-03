class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int color_same){
        int rol = image.size(), col = image[0].size();
        if(r<0 || c<0 || r >= rol || c >= col || image[r][c] != color_same || image[r][c] == color) return;
        image[r][c] = color;
        dfs(image,r-1,c,color,color_same);
        dfs(image,r+1,c,color,color_same);
        dfs(image,r,c-1,color,color_same);
        dfs(image,r,c+1,color,color_same);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};