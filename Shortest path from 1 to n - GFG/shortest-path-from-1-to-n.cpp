//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
// 
class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        int cnt = 0;
        while(n>=3){
            if(n%3==2){
                cnt += 2;
                n -= 2;
            }
            if(n%3==1) {
                cnt += 1;
                n -= 1;
            }
            if(n%3==0){
                cnt++;
                n /= 3;
            }
        }
        return cnt + n - 1;
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
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends