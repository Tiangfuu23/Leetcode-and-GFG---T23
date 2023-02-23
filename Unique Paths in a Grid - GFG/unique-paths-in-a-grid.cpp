//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        int mod = 1000000007;
        if(grid[0][0] == 0 || grid[n-1][m-1] == 0) return 0;
        for(int i = m-2; i>=0; i--){
            if(grid[n-1][i] == 0) continue;
            grid[n-1][i] = grid[n-1][i+1];
        }
        for(int i = n-2; i>=0; i--){
            if(grid[i][m-1] == 0) continue;
            grid[i][m-1] = grid[i+1][m-1];
        }
    for(int i = n-2; i>=0; i--){
        for(int j = m-2; j>=0; j--){
            if(grid[i][j] == 0) continue;
            grid[i][j] = grid[i+1][j]%mod + grid[i][j+1]%mod;
        }
    }
    return grid[0][0]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends