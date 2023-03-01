/**
 * @param {number} num
 * @return {number}
 */
var minimumSum = function(num) {
    const temp = [];
    while(num != 0){
        temp.push(num%10);
        // num /= 10; careful in JS cause it treat like floating point number
        num = Math.floor(num/10);
    }
    temp.sort((a,b)=>{return a-b});
    return temp[0]*10 + temp[1]*10 + temp[2] + temp[3];
};