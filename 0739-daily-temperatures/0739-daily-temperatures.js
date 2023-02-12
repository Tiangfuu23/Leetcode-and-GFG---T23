/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const stack = new Array(); // [ [value,index] ]
    temperatures.forEach(function(value,index,array) {
        // current number = value
        while(stack.length && value > stack.at(-1)[0]){
            array[stack.at(-1)[1]] = index - stack.pop()[1]; 
        }
        stack.push([value,index]);
    })
    while(stack.length) temperatures[stack.pop().at(-1)] = 0;
    return temperatures;
};