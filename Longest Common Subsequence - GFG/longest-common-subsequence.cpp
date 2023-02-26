//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    int lcs(string& s1, string& s2,int i, int j,vector<vector<int>>& dp){
        // base case
        if(i==0 || j == 0) return 0;
        // recursive case
        if(dp[i][j] != -1) return dp[i][j]; // memmoization
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + lcs(s1,s2,i-1,j-1,dp);
        }{
            return dp[i][j] = max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));
        }
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp (x+1, vector<int> (y+1,-1));
        return lcs(s1,s2,x,y,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends