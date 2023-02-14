//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<int> adj[], int u, int dest, vector<bool>& visited, int& cnt){
        visited[u] = true;
        if(u==dest){
            cnt++;
        }
        for(int& i : adj[u]){
            if(!visited[i]){
               dfs(adj,i,dest,visited,cnt); 
            }
        }
    visited[u] = false;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	   vector<int> adj[n];
	   for(auto i : edges){
	    adj[i[0]].push_back(i[1]);
	   }
	   // initialize
	   vector<bool> visited(n,false);
	   //vector<int> pred(n,-1);
	   int cnt = 0;
	   dfs(adj,s,d,visited,cnt);
	   return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends