/*
    partitionX + partitionY = (x + y )/2
    found:
        maxLeftX <= maxRight Y
        maxLeftY <= maxRight X
    else if
        maxLeftX > maxRightY then move toward left in x 
    else 
        move toward right in X
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2,nums1);
        int l = 0, r = n;
        while(l<=r){
            int partitionX = (l+r)/2;
            // partX -> no of element inpartitionX
            int partitionY = (n+m)/2-partitionX;

            double maxLeftX = partitionX == 0 ? INT_MIN : nums1[partitionX-1];
            double minRightX = partitionX == n ? INT_MAX : nums1[partitionX];

            double maxLeftY = partitionY == 0 ? INT_MIN : nums2[partitionY-1];
            double minRightY = partitionY == m? INT_MAX : nums2[partitionY];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((n+m)%2 != 0){
                    return fmin(minRightX,minRightY);
                }else{
                    return (fmax(maxLeftX,maxLeftY) + fmin(minRightX,minRightY))/2; 
                }
            }else if(maxLeftX > minRightY){
                r = partitionX -1;
            }else{
                l = partitionX + 1;
            }
        }
    return 0;
    }
};