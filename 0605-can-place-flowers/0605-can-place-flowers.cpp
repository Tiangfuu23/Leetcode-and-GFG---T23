class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        if(n == 0) return true;
        if(sz == 1 && flowerbed[0] == 0) return true;
        if(sz == 1 && flowerbed[0] == 1) return false;
        int cnt = 0;
        for(int i = 0; i<sz; i++){
            if(i==0){
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0){
                    cnt++;
                    flowerbed[i] = 1;
                }
            }else if(i==sz-1){
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0){
                    cnt++;
                    flowerbed[i] = 1;
                }
            }else{
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
        }
        return n<=cnt;
    }
};