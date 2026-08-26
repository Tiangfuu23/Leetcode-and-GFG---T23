// Brutal forces 1: 
// for each subarrays ~ regtangles:
//      find width & height of regtangle -> calc it's are
// Time complexity (O(n^2))
// Brutal forces 2:
// for each bar
//      we need to find l where l < i & h[l] < h[i] & l is max
//      and also find r where r > i & h[r] < h[i] & r is min
//      then maximum area which bar at index i can have = h[i] * (r-1 - (l+1) + 1 ) = h[i] * (r-l-1)
// Time complexity = O(n^2)
// Optimize method -> increasing order in height stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            // ans = max(ans, i);
            while(!st.empty() && heights[i] < heights[st.top()]){
                int top = st.top(); st.pop();
                int left_boundary = st.empty() ? -1 : st.top();
                int area = heights[top] * (i - left_boundary - 1);
                ans = max(ans, area); 
            }
            st.push(i);
        }

        int boundary_right = st.empty() ? 0 : st.top();
        while(!st.empty()){
            int top = st.top(); st.pop();
            int boundary_left;
            int area;
            if(st.empty()){
                boundary_left = 0;
                area = heights[top] * (boundary_right - boundary_left + 1);
            }else{
                while(!st.empty() && heights[top] == heights[st.top()]){
                    st.pop();
                }
                boundary_left = st.empty() ? 0 : st.top() + 1;
                area = heights[top] * (boundary_right - boundary_left + 1);
            }
        
            ans = max(ans, area); 
        }
        return ans;
    }
};