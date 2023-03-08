// check if we exclusive the edge weight of mst increase or not ?
// if yes -> cirtical
// if no check if we include that edge, whether w of mst is same as original mst or not 
//      if yes -> pseudo critical
//      if no -> trash
class unionFind {
    private:
        vector<int> parent,size;
    public:
        unionFind(int n){
            parent.resize(n);
            for(int i = 0; i<n; i++) parent[i] = i;
            size.resize(n,1);
        }
        int find(int x){
            if(parent[x] == x) return x;
            return find(parent[x]);
        }
        bool unite(int a, int b){
            a = find(a);
            b = find(b);
            if(a == b) return false;
            if(size[a] > size[b]){
                parent[b] = a;
                size[a] += size[b];
            }else{
                parent[a] = b;
                size[b] += size[a];
            }
            return true;
        }
};

class Solution {
public:
    int getMST(vector<vector<int>>& edge_list, int n, int edge_block, int pre_edge = -1){
        unionFind uf(n);
        int weight = 0;
        if(pre_edge != -1){
            weight += edge_list[pre_edge][2];
            uf.unite(edge_list[pre_edge][0],edge_list[pre_edge][1]);
        }
        for(int i = 0; i<edge_list.size(); i++){
            if(i == edge_block) continue;
            if(uf.unite(edge_list[i][0], edge_list[i][1])) weight += edge_list[i][2];
        }
        for(int i =0; i<n; i++){
            if(uf.find(i) != uf.find(0)) return INT_MAX;
        }
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i<edges.size(); i++) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b)->bool{
            return a[2] < b[2];
        });
        vector<int> critical,pseudo_critical;
        int ori_mst = getMST(edges,n,-1,-1);
        for(int i = 0; i<edges.size(); i++){
            if(ori_mst < getMST(edges,n,i,-1)) critical.push_back(edges[i][3]);
            else if (ori_mst == getMST(edges,n,-1,i)) pseudo_critical.push_back(edges[i][3]); 
        }
        return {critical,pseudo_critical};
    }
};