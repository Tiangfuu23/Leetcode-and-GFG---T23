//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int target) {
        int ans = 0;
	    unordered_map<int,int> visit; // value -- freq
	    for(int i = 0; i<n; i++){
		    int curr_number = arr[i];
		    int differ = target - curr_number;
		    if(visit.find(differ) != visit.end()){
			    ans += visit[differ];
		    }
		    if(visit.find(curr_number) != visit.end()){
			    visit[curr_number]++;
		    }else{
			    visit.insert({curr_number,1});
		    }
	    }
	return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends