class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> s; // temp - index
        for(int i = 0; i<n; i++){
            while(!s.empty() && temperatures[i] > s.top().first){
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        return res;
    }
};