// k = [1,.... max[piles]]
// find first integer that statisfies the property  
class Solution {
public:
    bool valid(vector<int> piles, int h, int num){
        long long cnt = 0;
        for(int i = 0; i<piles.size(); i++){
            cnt += ceil(piles[i]*1.0/num);
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(),piles.end());
        int l = 1, r = max, res = max;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(valid(piles,h,mid)){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        } 
    return res;
    }
};