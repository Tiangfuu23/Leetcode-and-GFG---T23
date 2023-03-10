class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<pair<int,int>> s; // value-index
        s.push({INT_MAX,0});
        int n = arr.size();
        for(int i = 0; i<n; i++){
            int val = arr[i];
            while(!s.empty() && val > s.top().first){
                s.pop();
            }
            s.push({val,i});
        }
        while(!s.empty()){
            int i = s.top().second-1;
            int val = s.top().first;
            s.pop();
            while(i>=0 && i>=s.top().second) arr[i--] = val;
        }
        arr[n-1] = -1;
        return arr;
    }
};