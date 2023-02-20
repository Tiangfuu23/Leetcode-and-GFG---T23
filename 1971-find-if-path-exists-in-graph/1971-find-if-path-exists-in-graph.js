/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @return {boolean}
 */
var validPath = function(n, edges, source, destination) {
    // edge case
    if(source == destination) return true;
    const visited = new Array(n).fill(false);
    const pred = new Array(n).fill(-1);
    // adj lists
    const adj = Array.from(new Array(n), ()=>{return []});
    for(let i of edges){
        adj[i[0]].push(i[1]);
        adj[i[1]].push(i[0]);
    }
    const dfs = function (v) {
        visited[v] = true;
        for(let i of adj[v]){
            if(!visited[i]){
                pred[i] = v;
                dfs(i);
            }
        }
    }
    dfs(source);
    return pred[destination] !== -1;
};