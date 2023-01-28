class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> temp; // position - speed
        int n = position.size();
        for(int i = 0; i<n; i++) temp.emplace_back(position[i],speed[i]);
        sort(temp.begin(), temp.end(), greater<pair<int,int>>()); // sort in decreasing order
        stack<pair<int,int>> s;
        s.push(temp[0]);
        for(int i = 1; i<n; i++){
            float time_next_car = (target - s.top().first)*1.0/(s.top().second);
            float time_curr_car = (target - temp[i].first)*1.0/(temp[i].second);
            if(time_curr_car > time_next_car){
                s.push(temp[i]);
            }
        }
        return s.size();
    }
};