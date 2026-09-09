class MyCalendar {
public:
    // ununordered_map<int> mp;
    vector<pair<int, int>> arr;
    MyCalendar() {
        // mp.clear();
        arr = vector<pair<int,int>>();
    }
    
    bool book(int startTime, int endTime) {
        // int m = (start + endTime)/2;
        // if(mp.find(m) != mp.end()){
        //     return true
        // }
        for(auto p : arr){
            if(!(endTime <= p.first || startTime >= p.second))
                return false;
        }
        arr.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */