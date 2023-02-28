//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
         unordered_map<char,int> mp; // char - redefined value
         for(int i = 0; i<n; i++){
            mp.insert({x[i],b[i]});
         }
         
        // prefix sum solution
        int sz = w.size();
        int prefix[sz]; prefix[0] = mp.find(w[0]) == mp.end() ? w[0] : mp[w[0]];
        for(int i = 0; i<sz; i++) prefix[i] = prefix[i-1] + (mp.find((char)w[i]) == mp.end() ? w[i] : mp[(char)w[i]]);
        int ind_min = -1;
        pair<int,int> min_sub_arr = {0,-1}, max_sub_arr = {prefix[0],0};
        for(int i = 0; i<sz; i++){
            if(prefix[i] - min_sub_arr.first > max_sub_arr.first){
                ind_min = min_sub_arr.second;
                max_sub_arr = {prefix[i]-min_sub_arr.first,i};
            }
            if(prefix[i] < min_sub_arr.first) min_sub_arr = {prefix[i],i};
        }
        string ans = "";
        for(int i = ind_min + 1; i<=max_sub_arr.second; i++) ans += w[i];
        return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends