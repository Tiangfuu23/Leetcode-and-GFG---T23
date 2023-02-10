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
function check(V, res, adj) {
    if(V!=res.length) return 0;
    let map = new Array(V);
    map.fill(-1);
    for (let i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (let i = 0; i < V; i++) {
        for (const v of adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

function main() {
    let t = parseInt(readLine());
    for(let i=0;i<t;i++)
    {
        let input_line = readLine().split(' ');
        let m = parseInt(input_line[0]);
        let n = parseInt(input_line[1]);
        let adj = new Array(n);
        for(let i=0;i<n;i++)
        {
            adj[i] = new Array();
        }
        for(let i=0;i<m;i++)
        {
            input_line = readLine().split(' ');
           
            let u = parseInt(input_line[0]);
            let v = parseInt(input_line[1]);
            adj[u].push(v);
        }
        let obj = new Solution();
        let res = obj.topoSort(n, adj);
        console.log(check(n,res,adj));
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} V
 * @param {number[][]} adj
 * @returns {number[]}
*/
class Solution 
{
    //Function to return list containing vertices in Topological order.
    topoSort(V, adj)
    {
        const visited = new Array(V).fill(false);
        const stack = [];
        
        const dfs = function(u){
            visited[u] = true;
            for(let i = 0; i < adj[u].length; i++){
                const adj_vertex = adj[u][i];
                if(!visited[adj_vertex]) dfs(adj_vertex);    
            }
            stack.push(u);
        } 
        for(let i = 0; i<V; i++){
            if(!visited[i]) dfs(i);
        }
        const ans = new Array();
        while(stack.length){
            ans.push(stack.pop());
        }
        return ans;
    }
}