//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int find(int parent[], int x){
        if(x==parent[x]) return x;
        return find(parent, parent[x]);
    }
    bool unite(int a, int b, int parent[], int size[]){
        a = find(parent,a);
        b = find(parent,b);
        if(a==b){
            return false;
        }
        if(size[a] > size[b]){
            parent[b] = a;
            size[a] += size[b];
        }else{
            parent[a] = b;
            size[b] += size[a];
        }
        return true;
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    // make set
	    int parent[V]; for(int i = 0; i<V; i++) parent[i] = i;
	    int size[V]; for(int i = 0; i<V; i++) size[i] = 1;
	    // for each edge in graph
	    for(int i = 0; i<V; i++){
	        for(int j : adj[i]){
	            if(j>i){
	                if(!unite(i,j,parent,size)) return 1;
	            }
	        }
	    }
	 return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends