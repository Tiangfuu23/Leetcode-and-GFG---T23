/**
 * @param {number[][]} points
 * @return {number}
 */
var minCostConnectPoints = function(points) {
    const v = points.length;
    const find = (x) =>{
        if(parent[x] === x) return x;
        return find(parent[x]);
    }
    const unite = function (a,b) {
        a = find(a);
        b = find(b);
        if(a==b) return false;
        if(size[a]>size[b]){
            parent[b] = a;
            size[a] += size[b];
        }else{
            parent[a] = b;
            size[b] += size[a];
        }
        return true;
    }
    const weight = function (v1,v2) {
        return Math.abs(v1[0]-v2[0]) + Math.abs(v1[1]-v2[1]);
    }
//     Make edge list 
    const edge_lists = [];
    // [ [weight,intial vertex, terminal vertex] ]
    for(let i =0; i<v; i++){
        for(let j = i+1; j<v; j++){
            edge_lists.push([weight(points[i],points[j]),i,j]);
        }
    }
    edge_lists.sort((a,b)=>{return a[0]-b[0]});
    //
    // make set
    const parent = new Array(v);
    for(let i =0; i<v; i++) parent[i] = i;
    const size = new Array(v).fill(1);
    let ans = 0;
    edge_lists.forEach(function(tp){
        if(unite(tp[1],tp[2])) ans += tp[0];      
    });
    return ans;
};