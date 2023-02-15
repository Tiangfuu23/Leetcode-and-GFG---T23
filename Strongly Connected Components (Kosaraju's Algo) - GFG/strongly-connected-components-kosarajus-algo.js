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
        let input_ar0 = readLine().split(' ').map(x=>parseInt(x));
        let v = input_ar0[0];
        let e = input_ar0[1];
        
        let arr = [];
        let obj = new Solution();
        for(let i=0;i<e;i++)
        {
            let input_line = readLine().split(' ');
            arr.push(input_line);
        }
        let ans = obj.kosaraju(arr,v,e);
        console.log(ans);
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[][]} arr
 * @param {number} v
 * @param {number} e
 * @returns {number}
*/
class Solution {
    kosaraju(arr, v, e) {
        // note that arr is edge list not adj list
        const adj = Array.from( Array(v), ()=>{return []});
        for(let i = 0; i<arr.length; i++){
            adj[arr[i][0]].push(arr[i][1]);
        }
        const stack = [];
        const visited = new Array(v).fill(false);
        const dfs = function (u) {
            visited[u] = true;
            if(adj[u]){
                for(let i = 0; i<adj[u].length; i++){
                    const adj_vertex = adj[u][i]
                    if(!visited[adj_vertex]) dfs(adj_vertex);
                }
            }
            stack.push(Number(u));
        }
        for(let i = 0; i<v; i++) if(!visited[i]) dfs(i);
        // construct a transpose adj list
        const adj_rev = Array.from( Array(v), ()=>{return []});
        for(let i = 0; i<v; i++){
            if(!adj[i]) continue;
            adj[i].forEach( (adj_vertex) => {
                adj_rev[adj_vertex].push(i);
            } )
        }
        //
        visited.fill(false);
        const dfsUntil = function (u) {
            visited[u] = true;
            if(!adj_rev[u]) return;
            adj_rev[u].forEach((i)=>{
                if(!visited[i]) dfsUntil(i);
            })
        }
        let count = 0;
        while(stack.length){
            const curr_vertex = stack.pop();
            if(!visited[curr_vertex]){
                count++;
                dfsUntil(curr_vertex);
            }
        }
    return count;
    }
}