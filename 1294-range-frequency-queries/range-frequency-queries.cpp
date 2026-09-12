class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp; // value -> stored indices
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        // if(mp.find(value) == mp.end())
        //     return 0;

        // vector<int>& arr = mp[value];
        // auto li = lower_bound(arr.begin(), arr.end(), left);
        // auto ri = upper_bound(arr.begin(), arr.end(), right);
        // int l = li - arr.begin();
        // int r = ri - arr.begin() - 1;

        // return r - l + 1;
        auto it = mp.find(value);
        if (it == mp.end())
            return 0;
        vector<int>& v = it->second;
        return upper_bound(v.begin(), v.end(), right) -
               lower_bound(v.begin(), v.end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */