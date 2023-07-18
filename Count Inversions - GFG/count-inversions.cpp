//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long low, long long mid, long long high){
        long long cnt_inversion = 0, sz = high - low + 1, l1 = low, l2 = mid+1, k = 0;
        vector<long long> temp(sz);
        while(l1 <= mid && l2 <= high){
            if(arr[l1] <= arr[l2]) temp[k++] = arr[l1++];
            else {
                temp[k++] = arr[l2++];
                cnt_inversion += mid-l1 + 1;
            }
        }
        while(l1<=mid){
            temp[k++] = arr[l1++];
        }
        while(l2<=high) temp[k++] = arr[l2++];
        for(long long i = 0; i<sz; i++){
            arr[low+i] = temp[i];
        }
        return cnt_inversion;
    }
    
    long long mergeSort(long long arr[], long long l, long long r){
        long long cnt_inversion = 0;
        if(l<r){
            long long mid = ((r-l)/2 + l);
            cnt_inversion += mergeSort(arr,l,mid);
            cnt_inversion += mergeSort(arr,mid+1,r);
            cnt_inversion += merge(arr,l,mid,r);
        }
        return cnt_inversion;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends