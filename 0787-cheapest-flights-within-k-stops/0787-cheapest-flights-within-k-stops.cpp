class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // //initilize adj list
        // vector<pair<int,int>> adj[n];
        // for(auto i : flights){
        //     adj[i[0]].push_back({i[1],i[2]})
        // }
        // bellman-ford
        vector<int> price(n,10e6);
        price[src] = 0;
        for(int j = 1; j<= k+1; j++){
            vector<int> temp_price = price;
            for(auto i : flights){
                price[i[1]] = fmin(price[i[1]], temp_price[i[0]]+i[2]); 
            }
        }
    return price[dst] == 10e6 ? -1 : price[dst];
    }
};