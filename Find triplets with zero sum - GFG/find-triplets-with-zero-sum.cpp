//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/ // [-30,-6,4,11,13,63,85]
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr, arr+n);
        for(int i = 0; i<n; i++){
            int curr_number = arr[i]; // -> target = -curr_number
            if(curr_number > 0) return false;
            int l = i+1, r = n-1;
            while(l<r){
                if(arr[l]+arr[r]> -curr_number) r--;
                else if(arr[l]+arr[r]< -curr_number) l++;
                else return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends