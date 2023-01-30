//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void sieve(vector<bool>& isPrime, int n){
        //isPrime[0] = isPrime[1] = false;
        for(int i =2 ; i*i<=n; i++){
            if(isPrime[i]){
                for(int j = i*i; j<=n; j+=i) isPrime[j] = false;
            }
        }
    }
    vector<int> primeDivision(int N){
        // code here
        vector<int> res;
        vector<bool> isPrime(N+1, true);
        sieve(isPrime,N);
        int l = 2, r = N;
        while(l<=r){
            if(!isPrime[l]) l++;
            else if (!isPrime[r]) r--;
            else if (l+r>N) r--;
            else if(l+r<N) l++;
            else{
                res.push_back(l); 
                res.push_back(r);
                return res;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends