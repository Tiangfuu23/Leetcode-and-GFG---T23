// first find out where is the 'target' row ? 
// then do binary search in that row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int low = 0, high = row-1;
        // 1. find out the 'target' row  
        while (low < high){
            int mid = (low+high)/2;
            if(target < matrix[mid][0]) high = high - 1;
            else if(target > matrix[mid][col-1]) low = low + 1;
            else low = high = mid;
        }
        // here low = high = 'target' row 
        int l = 0, r = col - 1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[low][mid] == target) return true;
            else if(matrix[low][mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};