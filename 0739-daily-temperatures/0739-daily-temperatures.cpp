// same as find next greater number 
// using stack time O(n) space O(n)
class Solution {
public: 
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s; // value - index 
        for(int i = 0; i<temperatures.size(); i++){
            int curr_number = temperatures[i];
            while(!s.empty() && curr_number > s.top().first){
                temperatures[s.top().second] = i-s.top().second;
                s.pop();
            }
            s.push({curr_number,i});
        }
        while(!s.empty()){
            temperatures[s.top().second] = 0;
            s.pop();
        }
    return temperatures;
    }
};