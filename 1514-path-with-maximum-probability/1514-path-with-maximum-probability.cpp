class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // initialize
        vector<pair<int,double>> adj[n]; // adj vertex - weight
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> prob(n,INT_MIN);
        vector<bool> processed(n,false);
        priority_queue<pair<double,int>> pq;
        prob[start] = 1;
        pq.push({1,start});
        while(!pq.empty()){
            int curr_vertex = pq.top().second; pq.pop();
            if(processed[curr_vertex]) continue;
            processed[curr_vertex] = true;
            for(auto i : adj[curr_vertex]){
                int adj_vertex = i.first;
                double w = i.second;
                if(prob[curr_vertex]*w > prob[adj_vertex]){
                    // relax 
                    prob[adj_vertex] = prob[curr_vertex]*w;
                    pq.push({prob[adj_vertex],adj_vertex});
                }
            }
        }
    return prob[end] == INT_MIN ? 0 : prob[end];
    }
};