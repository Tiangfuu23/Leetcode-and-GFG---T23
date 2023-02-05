//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // weight - vertex
        vector<int> dist(V,INT_MAX);
        vector<bool> processed(V,false);
        //
        pq.push({0,s});
        dist[s] = 0;
        while(!pq.empty()){
            int curr_vertex = pq.top().second; pq.pop();
            if(processed[curr_vertex]) continue;
            processed[curr_vertex] = true;
            for(auto i : adj[curr_vertex]){
                int adj_vertex = i[0];
                int weight = i[1];
                if(dist[curr_vertex]+weight < dist[adj_vertex]){
                    // relaxation 
                    dist[adj_vertex] = dist[curr_vertex] + weight;
                    pq.push({dist[adj_vertex],adj_vertex});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends