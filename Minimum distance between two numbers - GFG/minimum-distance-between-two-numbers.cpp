//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 
class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        int prev = -1;
        int min_dis = INT_MAX;
        for(int i =0 ; i<n; i++){
            if(arr[i] == x || arr[i] == y){
                if(prev != -1 && arr[i] != arr[prev]){
                    min_dis = min(i-prev,min_dis);
                }
                prev = i;
            }            
        }
        if(min_dis == INT_MAX) return -1;
        return min_dis;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends