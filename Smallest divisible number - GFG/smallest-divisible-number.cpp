//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    long long lcm(long long a, long long b){
        return a*b/__gcd(a,b);
    }
    long long getSmallestDivNum(long long n){
        // code here
        long long ans = 1;
        for(int i = 1; i<=n; i++) ans = lcm(ans,i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends