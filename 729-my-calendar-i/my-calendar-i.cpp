class MyCalendar {
public:
    map<int, int> mp; // end time - start time
    MyCalendar() {
        // mp.clear();
    }
    
    bool book(int startTime, int endTime) {
        auto checkedEvent = mp.upper_bound(startTime);
        if(checkedEvent != mp.end() && checkedEvent->second < endTime) // exist event which end time > current start time
            return false;
        
        mp.insert({endTime, startTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */