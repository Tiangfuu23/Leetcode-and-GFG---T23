/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    flowerbed.unshift(0);
    flowerbed.push(0);
    let cnt  = 0;
    for(let i = 1; i<=flowerbed.length-2; i++){
        if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
            cnt++;
            flowerbed[i] = 1;
        }
    }
    return cnt >= n;
};