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
        if(n==0){
            if(m%2!=0) return nums2[m/2];
            else return (nums2[m/2-1]*1.0+nums2[m/2])/2;
        }
        if(n > m) return findMedianSortedArrays(nums2,nums1);
        int l = -1, r = n;
        while(l<=r){
            int partitionX = (l+r)/2 ;
            // number of element in partX partitionX + 1;
            // no of elements in parY = (n+m)/2 - partitionX - 1
            int partitionY = (n+m)/2-partitionX - 2;

            double maxLeftX = partitionX == -1 ? INT_MIN : nums1[partitionX];
            double minRightX = partitionX == n-1 ? INT_MAX : nums1[partitionX+1];

            double maxLeftY = partitionY == -1 ? INT_MIN : nums2[partitionY];
            double minRightY = partitionY == m-1 ? INT_MAX : nums2[partitionY+1];
            
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