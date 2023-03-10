// subproblem : M[i] -> is maximum value at A[i:] ? 
// relation : M[i] = max(A[i],M[i-1])
// 
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1, n = arr.size();
        for(int i = n-1; i>=0; i--){
            int temp = arr[i];
            arr[i] = max;
            max = fmax(max,temp);
        }
    return arr;
    }
};