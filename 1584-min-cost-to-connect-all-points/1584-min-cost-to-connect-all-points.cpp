// Prim's algorithm // timeO(v^2)
class Solution {
public:
    int weight(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<int> key(v, INT_MAX);
        vector<bool> inMST(v,false);
        // 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // key - vertex
        pq.push({0,0});
        key[0] = 0;
        while(!pq.empty()){
            int curr_vertex = pq.top().second; pq.pop();
            if(inMST[curr_vertex]) continue;
            inMST[curr_vertex] = true;
            for(int i =0; i<v; i++){
                int adj_vertex = i;
                int w = weight(points[curr_vertex],points[adj_vertex]);
                if(!inMST[i] && w < key[adj_vertex]){
                    key[adj_vertex] = w;
                    pq.push({w,adj_vertex});
                }
            }
        }
        int ans = 0;
        for(int& i : key) ans += i;
        return ans;
    }
};