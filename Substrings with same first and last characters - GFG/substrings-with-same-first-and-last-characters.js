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
    let s = readLine().trim();
    let obj = new Solution();
    let res = obj.countSubstringWithEqualEnds(s);
    console.log(res);
  }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {string} s
 * @return {number}
 */
class Solution {
  countSubstringWithEqualEnds(s) {
    const map = new Map();
    for(let i = 0; i<s.length; i++){
        map.set(s[i], 1 + (map.has(s[i]) ? map.get(s[i]) : 0));
    }
    let ans = 0;
    for(let i of map.values()) ans += i*(i+1)/2
    return ans;
  }
}
