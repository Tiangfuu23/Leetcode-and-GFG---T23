class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // edge case
        if(source == destination) return true;
        // make adj list;
        vector<int> adj[n];
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> pred(n,-1);
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        // bfs
        while(!q.empty()){
            int curr_vertex = q.front(); q.pop();
            for(auto adj_vertex : adj[curr_vertex]){
                if(!visited[adj_vertex]){
                    visited[adj_vertex] = true;
                    q.push(adj_vertex);
                    pred[adj_vertex] = curr_vertex;
                }
            }
        }
        return pred[destination] != -1;
    }
};