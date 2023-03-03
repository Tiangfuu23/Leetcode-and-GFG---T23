class Solution {
public: //O(n) solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> sorted(n+m,0);
        int l = 0, r = 0, k = 0;
        while(l<n && r <m) sorted[k++] = nums1[l] < nums2[r] ? nums1[l++] : nums2[r++];
        while(l<n) sorted[k++] = nums1[l++];
        while(r<m) sorted[k++] = nums2[r++];
        double ans = 0;
        if((n+m)%2 != 0){
            ans = sorted[(n+m)/2];
        }else{
            ans = sorted[(n+m)/2 -1] + sorted[(n+m)/2];
            ans /= 2;
        }
        return ans;
    }
};