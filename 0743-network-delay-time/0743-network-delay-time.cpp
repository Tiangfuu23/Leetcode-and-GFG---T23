/*
[[2,1,1],
 [2,3,1],
 [3,4,1]
],
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create an adjacency list
        vector<pair<int,int>> adj[n+1]; // adj vertex - weighted edge
        for(int i = 0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // weight-edge
        vector<int> dis(n+1,INT_MAX);
        // 
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            int curr_vertex = pq.top().second;
            pq.pop();
            for(auto i : adj[curr_vertex]){
                int adj_vertex = i.first;
                int w = i.second;
                if(dis[curr_vertex]+w <dis[adj_vertex]){
                    dis[adj_vertex] = dis[curr_vertex] + w;
                    pq.push({dis[adj_vertex],adj_vertex});
                }
            }
        }
        int res = 0;
        for(int i = 1; i<=n; i++){
            if(dis[i] == INT_MAX) return -1;
            res = max(res,dis[i]);
        }
        return res;
    }
};