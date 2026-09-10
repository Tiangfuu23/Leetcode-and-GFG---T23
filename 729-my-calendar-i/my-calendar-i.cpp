class MyCalendar {
public:
    map<int, int> mp; // end time - start time
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int startTime, int endTime) {
        auto leftCheckEvent = mp.upper_bound(startTime);
        if(leftCheckEvent != mp.end() && leftCheckEvent->second < endTime) // exist event which end time > current start time
            return false;
            
        // auto rightCheckEvent = mp.lower_bound(endTime);
        // if(rightCheckEvent != mp.end() && rightCheckEvent->second < endTime)
        //     return false;

        mp.insert({endTime, startTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */