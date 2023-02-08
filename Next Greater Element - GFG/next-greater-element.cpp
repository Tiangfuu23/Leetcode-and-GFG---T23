//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
       stack<pair<long long,int>> s; // value-index
       vector<long long> ans(n,-1);
       s.push({arr[0],0});
       for(int i = 1; i<n; i++){
           long long curr = arr[i]; // prev = s.top().first
           while(!s.empty() && curr>s.top().first){
               ans[s.top().second] = curr;
               s.pop();
           }
           s.push({curr,i});
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends