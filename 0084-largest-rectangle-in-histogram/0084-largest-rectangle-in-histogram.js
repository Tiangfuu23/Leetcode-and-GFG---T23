/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    let ans = 0;
    const stack = []; // [ [started_index - hegiht] ]
    heights.forEach(function(height,i){
        if(!stack.length || height >= stack.at(-1)[1]) stack.push([i,height]);
        else{
            let [temp, start_index, pre_height] = [i,stack.at(-1)[0],stack.at(-1)[1]];
            while(stack.length && height < pre_height){
                stack.pop();
                ans = Math.max(ans, pre_height*(i-start_index));
                temp = start_index;
                if(stack.length){
                    [start_index,pre_height]  = [stack.at(-1)[0],stack.at(-1)[1]];
                }
            }
            stack.push([temp,height]);
        }
    })
    while(stack.length){
        ans = Math.max(ans,stack.at(-1)[1]*(heights.length-stack.at(-1)[0]));
        stack.pop();
    } 
    return ans;
};