//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public: // greedy approach
    string smallestNumber(int s, int d){
        if(s==0 && d!= 1) return "-1";
        if(d*9 < s ) return "-1";
        vector<int> res(d,0);
        int carry  = 1; s--;
        for(int i = res.size()-1; i>=0; i--){
            if(s>9){
                res[i] = 9;
                s -= 9;
            }else{
                res[i] = s;
                s = 0;
            }
        }
        res[0] += carry;
    stringstream ss;
    for(auto i : res) ss << i;
    return ss.str();
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends