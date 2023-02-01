//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        const long long mod = 1000000007;
        if(n==1 || n==2) return 1;
        vector<long long> fibo(n+1);
        fibo[1] = fibo[2] = 1;
        for(int i = 3; i<=n ; i++){
            long long f1= fibo[i-1]%mod;
            long long f2= fibo[i-2]%mod;
            fibo[i] = f1 + f2;
        }
        return fibo[n]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends