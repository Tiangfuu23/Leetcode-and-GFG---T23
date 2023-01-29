// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// [F,F,F,F,T,T]
// [F,T,T,T,T]
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l<r){
            int mid = l + (r-l)/2;
            if(isBadVersion(mid)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return isBadVersion(l) ? l : l+1;
    }
};