//{ Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
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
  for (; i < t; i++) {
    let n = parseInt(readLine());
    let input = readLine().split(' ').map(x => parseInt(x));
    let arr = [];
    for(let i=0;i<n;i++){
        arr.push(input[i]);
    }
    let obj = new Solution();
    let res = obj.smallestpositive(arr, n);
    console.log(res);
  }
}


// } Driver Code Ends


//User function Template for javascript


/**
 * @param {number[]} arr
 * @param {number} n
 * @returns {number}
 */

class Solution {
    smallestpositive(arr, n){
        let ans = 1;
        arr.sort((a,b)=>{return a-b});
        for(let val of arr){
            if(val > ans) return ans;
            else ans += val;
        }
        return ans;
    }
}

