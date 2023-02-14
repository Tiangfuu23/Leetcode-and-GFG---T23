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
function printArray(arr) {
  let s = "";
  for (let i of arr) {
    s = s + i + " ";
  }
  console.log(s);
}
function main() {
  let t = parseInt(readLine());
  let i = 0;
  for (; i < t; i++) {
    let inputArr = readLine()
      .trim()
      .split(" ")
      .map((x) => parseInt(x));

    let [n, m, s, d] = inputArr;
    let edges = [];
    for (let j = 0; j < m; j++) {
      inputArr = readLine()
        .trim()
        .split(" ")
        .map((x) => parseInt(x));
      edges.push(inputArr);
    }
    let obj = new Solution();
    let res = obj.possible_paths(edges, n, s, d);
    console.log(res);
  }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[][]} edges
 * @param {number} n
 * @param {number} s
 * @param {number} d
 * @return {number}
 */

class Solution {
  possible_paths(edges, n, s, d) {
    const adj = new Array(n);
    for(let i = 0; i<n; i++) adj[i] = [];
    edges.forEach((i)=>{
        adj[i[0]].push(i[1]);
    })
    const visited = new Array(n).fill(false);
    let cnt = 0;
    const dfs = (u) => {
        visited[u] = true;
        if(u==d) cnt++;
        for(let i = 0; i<adj[u].length; i++){
            if(!visited[adj[u][i]]) dfs(adj[u][i]);
        }
        visited[u] = false;
    }
    dfs(s);
    return cnt;
  }
}