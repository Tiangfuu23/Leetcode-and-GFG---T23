// subproblem : what is minimum cost from day i till the end ? -> dp[i] 
// relate subproblems solutions : dp[i] = min{c0 + dp[i+1], c1 + dp[i+7], c2 + dp[i+30]}
// original : dp[0]
// base case dp[n>=len] = 0;
class Solution {
private:
    unordered_map<int,int> mp;
    unordered_map<int,int> dp;
public:
    int dfs(vector<int>& days,int i){
        if(i==days.size()) return 0;
        if(dp.find(i) != dp.end()) return dp[i]; // memmoize
        dp[i] = INT_MAX;
        for(auto choice : mp){
            int j = i;
            while(j<days.size() && days[j] < days[i] + choice.first) j++;
            dp[i] = fmin(dp[i],choice.second + dfs(days,j));
        }
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        mp.emplace(1,costs[0]);
        mp.emplace(7,costs[1]);
        mp.emplace(30,costs[2]);
        dfs(days,0);
        return dp[0];
    }
};