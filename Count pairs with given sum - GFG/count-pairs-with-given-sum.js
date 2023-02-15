//{ Driver Code Starts
//Initial Template for javascript

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let [n,k] = readLine().trim().split(" ").map((x) => parseInt(x)); 
        let arr = readLine().trim().split(" ").map((x) => parseInt(x)); 
        let obj = new Solution();
        let res = obj.getPairsCount(arr,n,k);
        console.log(res);
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} n
 * @param {number} k
 * @return {number}
*/

class Solution {
    getPairsCount(arr,n,target){
        let ans = 0;
        const map = new Map(); // value - freq 
        for(let i = 0; i<n; i++){
            const curr_number = arr[i];
            const differ = target - curr_number;
            if(map.has(differ)){
                ans += map.get(differ);
            }
            map.set(curr_number, 1 + (map.has(curr_number) ? map.get(curr_number) : 0));
        }
    return ans;
    }
}