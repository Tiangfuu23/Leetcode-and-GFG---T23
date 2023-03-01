//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++
// m[i] -> minimum sum (integer) that is not present in sum subset of array upto position i 
class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        using ll = long long;
        ll ans = 1; // ans ~ m[i-1]
        sort(array.begin(), array.end());
        for(int i = 0; i<n; i++){
            if(array[i] > ans) return ans;
            else{
                // maximum sum subset arr[i] + m[i-1] - 1;
                ans += array[i];
            }
        }
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
        int n;
        cin>>n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 

// } Driver Code Ends