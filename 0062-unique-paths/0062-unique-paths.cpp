class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int> (n,1));
            for(int i = m -2; i>=0; i--){
                for(int j = n-2; j>=0; j--){
                    arr[i][j] = arr[i+1][j] +arr[i][j+1];
                }
            }
        return arr[0][0];
    }
};