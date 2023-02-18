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
        let [n,m] = readLine().trim().split(" ").map((x) => parseInt(x));
        let adj = [];
        for(let i = 0;i<n;i++){
            adj[i] = new Array();
        }
        
        for(let j = 0;j<m;j++){
            let [u,v] =  readLine().trim().split(" ").map((x) => parseInt(x));
            adj[u].push(v);
            adj[v].push(u);
        }
        let obj = new Solution();
        let res = obj.detectCycle(n,adj);
        console.log(res);
    }
}

// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} n
 * @param {number[][]} adj
 * @return {number} 
*/

class Solution {
    detectCycle(n,adj){
       // makeset 
       const parent = new Array(n);
       for(let i = 0; i<parent.length; i++) parent[i] = i;
       const size = new Array(n).fill(1);
       // find representative
       const find = (x) =>{
           if(x==parent[x]) return x;
           return find(parent[x]);
       }
       const unite = function (a,b){
           a = find(a);
           b = find(b);
           if(a==b){
               return true;
               // containe cycle
           }
           if(size[a] > size[b]){
               parent[b] = a;
               size[a] += size[b];
           }else{
               parent[a] = b;
               size[b] += size[a];
           }
           return false;
       }
        for(let i = 0; i<n; i++){
            for(let j = 0; j<adj[i].length; j++){
                const adj_vertex = adj[i][j];
                if(adj_vertex > i){
                    if(unite(i,adj_vertex)) return 1;
                }
            }
        }
    return 0;
    }
}
