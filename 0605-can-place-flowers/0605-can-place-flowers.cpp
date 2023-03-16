class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int cnt = 0;
        for(int i = 1; i<=flowerbed.size() -2; i++){
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                cnt++;
                flowerbed[i] = 1;
            }
        }
        return n <= cnt;
    }
};