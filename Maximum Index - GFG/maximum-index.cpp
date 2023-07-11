//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int> leftMin(n),rightMax(n);
    	leftMin[0] = arr[0];
    	rightMax[n-1] = arr[n-1];
    	for(int i = 1; i<n; i++){
    		leftMin[i] = fmin(leftMin[i-1],arr[i]);
    		rightMax[n-1-i] = fmax(rightMax[n-i],arr[n-i-1]);
    	}
    	int i = 0, j = 0, diffMax = -1;
    	while(i < n && j < n){
    		if(leftMin[i] <= rightMax[j]){
    			diffMax = fmax(diffMax,j-i);
    			j++;
    		}
    		else i++;
    	}
    	return diffMax;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends