// check cycle in a graph by using topological sort 
class Solution {
private:
    bool check = true;
public:
    void dfs(vector<int> adj[],vector<bool>& visited,vector<bool> processed,int u){
        visited[u] = processed[u] = true;
        for(auto adj_vertex : adj[u]){
            if(processed[adj_vertex]){
                check = 0;
                return;
            }
            if(!visited[adj_vertex]) dfs(adj,visited,processed,adj_vertex);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create an adj list
        vector<int> adj[numCourses];
        for(auto i : prerequisites) adj[i[1]].push_back(i[0]);
        vector<bool> visited(numCourses,false);
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                vector<bool> processed(numCourses,false);
                dfs(adj,visited,processed,i);
                if(check==0) return false;
            }
        }
        return check;
    }
};