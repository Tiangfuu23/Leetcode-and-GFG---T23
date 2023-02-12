class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s; // index - height
        int max_area = 0;
        int n = heights.size();
        for(int i = 0; i<n; i++){
            if(s.empty() || heights[i] >= s.top().second) s.push({i,heights[i]});
            else{
                int temp = i;
                int pre_index = s.top().first;
                int pre_height = s.top().second;
                while(!s.empty() && heights[i] < pre_height){
                    s.pop();
                    max_area = max(max_area, pre_height*(i-pre_index));
                    temp = pre_index;
                    if(!s.empty()){
                        pre_index = s.top().first;
                        pre_height = s.top().second;
                    }
                }
                s.push({temp, heights[i]});
            }
        }
        while(!s.empty()){
            int curr_index = s.top().first;
            int curr_height = s.top().second;
            s.pop();
            max_area = max(max_area, curr_height * (n-curr_index));
        }
    return max_area;
    }
};